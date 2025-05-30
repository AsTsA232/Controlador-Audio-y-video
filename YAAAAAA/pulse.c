#include "stm32f10x.h"
//SEGUNDO MOTOR TIMER 3
//primer motor timer 2


void salida_pwm(){
RCC->APB1ENR |= (1 << 0);	//enable TIM2 clk
	TIM2->PSC=21;
	TIM2->ARR=65453;
	//TIM2->CCR2 = 3273;
	TIM2->CCMR1 |= (1 << 14) | (1 << 13); //select pwm mode ch2
	TIM2->CCER	|=	(1 << 4);	//enable ch2
	TIM2->CR1		|=	(1 << 0); //enable timer
	TIM2->CCR2 = 32727;
}

	