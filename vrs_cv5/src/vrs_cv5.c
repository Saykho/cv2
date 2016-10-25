/*
 * vrs_cv5.c
 *
 *  Created on: 18. 10. 2016
 *      Author: student
 */

#include <stddef.h>
#include "stm32l1xx.h"
#include "vrs_cv5.h"

uint32_t AD_value;

void ADC1_IRQHandler() {
	if (ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == SET)
		AD_value = ADC1->DR;
}
