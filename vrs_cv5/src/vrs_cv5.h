#ifndef __VRS_CV5
#define __VRS_CV5

#define USARTi USART2
#define GPIO_AF_USARTi GPIO_AF_USART2
#define USARTi_IRQn USART2_IRQn
#define RCC_APBjPeriph_USARTi RCC_APB1Periph_USART2
#define RCC_APBjPeriphClockCmd RCC_APB1PeriphClockCmd
//also change interrupt function name in vrs_cv5.c
//also change pins of UART communication in main.c

extern uint32_t AD_value;
extern uint32_t USART_input_value;
extern char *stringToSend;
extern char *stringBeingSent;

//Memory for strings (malloc should be avoided wherever possible)
extern char str1[50];
extern char str2[50];
extern char str3[50];
#endif //__VRS_CV5
