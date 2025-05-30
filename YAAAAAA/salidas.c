#include "stm32f10x.h"
void idle(void){
		GPIOB->ODR |= (1 << 0); // PB0 ON
    GPIOB->ODR |= (1 << 1); // PB1 ON
    GPIOB->ODR |= (1 << 3); // PB3 ON
    GPIOB->ODR |= (1 << 4); // PB4 ON
}

void leer(void){
	GPIOB->ODR &= ~(1 << 0); // PB0 OFF
	GPIOB->ODR |=  (1 << 3); // PB3 ON
	GPIOB->ODR &= ~(1 << 1); // PB1 OFF
	GPIOB->ODR &= ~(1 << 4); // PB4 OFF
}

void grabar (void){
   GPIOB->ODR &= ~(1 << 0); // PB0 OFF
   GPIOB->ODR |=  (1 << 1); // PB1 ON
   GPIOB->ODR &= ~(1 << 3); // PB3 OFF
   GPIOB->ODR &= ~(1 << 4); // PB4 OFF
}

void calibrar(void){
   GPIOB->ODR &= ~(1 << 0); // PB0 OFF
   GPIOB->ODR |=  (1 << 1); // PB1 ON
   GPIOB->ODR |=(1 << 3); // PB3 ON
   GPIOB->ODR &= ~(1 << 4); // PB4 OFF
}