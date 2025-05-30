#include "stm32f10x.h"
void init_gpio(void){
 // Habilitar reloj para GPIOA, GPIOB y AFIO
    RCC->APB2ENR |= (1 << 0); // AFIOEN
    RCC->APB2ENR |= (1 << 2); // IOPAEN
    RCC->APB2ENR |= (1 << 3); // IOPBEN

    // ?? Deshabilitar JTAG para liberar PB3 y PB4 (mantener SWD)
    AFIO->MAPR |= (1 << 25); // SWJ_CFG = 0b010

    // Entradas: PA0–PA4 
    GPIOB->CRL &= ~((0xF << 0) | (0xF << 8) | (0xF << 12)|(0xF << 16)|(0xF << 20)|(0xF << 24)|(0xF << 28));
    GPIOB->CRL |=  ((0x4 << 0) | (0x4 << 8) | (0x4 << 12)|(0x4 << 16)|(0x4 << 20)|(0x4 << 24)|(0x4 << 28));

    // Salidas: PB0, PB1, PB3, PB4 
    GPIOB->CRL &= ~((0xF << 0) | (0xF << 4) | (0xF << 12) | (0xF << 16));
    GPIOB->CRL |=  ((0x2 << 0) | (0x2 << 4) | (0x2 << 12) | (0x2 << 16));
	
		//PWM ----------------------------------------------------------
		//PA1 mode 2MHz.
		GPIOA->CRL |= (1 << 5);
		GPIOA->CRL &= ~(1 << 4);
		//PA1 alternate function pushpull
		GPIOA->CRL |= (1 << 7);
		GPIOA->CRL &= ~(1 << 6);

	
}