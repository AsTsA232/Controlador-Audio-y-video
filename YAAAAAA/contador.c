#include "stm32f10x.h"

void conteo_frecuencia(int cont){
	int aumentof = (GPIOA->IDR & (1 << 6)) ? 1 : 0;
	int disminuirf = (GPIOA->IDR & (1 << 7)) ? 1 : 0;
	
	if(aumentof==1 && cont<8){
		cont=cont+1;
	}else{
		cont=cont+0;
	}
	
	if (disminuirf==1 && cont>1){
		cont=cont-1;
	}else{
		cont=cont+0;
	}
}