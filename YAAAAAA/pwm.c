#include "stm32f10x.h"

void salida_pwm(int ARR, int PSC, int CCR2){
RCC->APB1ENR |= (1 << 0);	//enable TIM2 clk
	TIM2->PSC=PSC;
	TIM2->ARR=ARR;
	TIM2->CCR2 = CCR2;
	TIM2->CCMR1 |= (1 << 14) | (1 << 13); //select pwm mode ch2
	TIM2->CCER	|=	(1 << 4);	//enable ch2
	TIM2->CR1		|=	(1 << 0); //enable timer

}

void frecuenciaspwm(int contador){

if(contador==1){           //3KHZ
	salida_pwm(23999,0,2400);
}else if(contador==2){			//4KHZ
	salida_pwm(17999,0,1800);
}else if(contador==3){			//5KHZ
	salida_pwm(14399,0,1440);
}else if(contador==4){			//6KHZ
	salida_pwm(11999,0,1200);	
}else if(contador==5){			//8KHZ
	salida_pwm(8999,0,900);	
}else if(contador==6){			//10KHZ
	salida_pwm(7199,0,720);	
}else if(contador==7){			//12KHZ
	salida_pwm(5999,0,600);	
}else{
	contador=4;
}

}

	