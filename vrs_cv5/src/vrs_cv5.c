/*
 * vrs_cv5.c
 *
 *  Created on: 18. 10. 2016
 *      Author: student
 */

#include <stddef.h>
#include <stdlib.h>
#include "stm32l1xx.h"
#include "vrs_cv5.h"

uint32_t AD_value;
uint32_t USART_input_value;

//Memory for strings (malloc should be avoided wherever possible)
char str1[50] = "";
char str2[50] = "";
char str3[50] = "";

char *stringToSend;
char *stringBeingSent;
char *actualCharacterToSend;

void initStrings() {
	stringToSend = str1;
	stringBeingSent = str1;
	actualCharacterToSend = str1;
}

void ADC1_IRQHandler() {
	if (ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == SET)
		AD_value = ADC1->DR;
}

void USART2_IRQHandler() {
	if (USART_GetFlagStatus(USARTi, USART_FLAG_RXNE) == SET) {
		USART_input_value = USART_ReceiveData(USARTi);
		USART_ClearFlag(USARTi, USART_FLAG_RXNE);
	}
	else if (USART_GetFlagStatus(USARTi, USART_FLAG_TXE) == SET) {
		if (!*actualCharacterToSend) {
			if (stringBeingSent != stringToSend) {
				stringBeingSent = stringToSend;
				actualCharacterToSend = stringBeingSent;
			}
		}

		USART_SendData(USARTi, *actualCharacterToSend);
		if (*actualCharacterToSend)
			actualCharacterToSend++;
		USART_ClearFlag(USARTi, USART_FLAG_TC);
	}
}
