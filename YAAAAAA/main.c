#include "stm32f10x.h"
#include "gpio.h"
#include "salidas.h"
#include "pwm.h"
#include "contador.h"

void delay(volatile unsigned int t) {
    while (t--);
}

int main(void) {
		init_gpio();

    int estado_act0,estado_act3,estado_act4, estado_act5;
		int tope_mem;
    int led0 = 0;
    int led1 = 0;
		int contadorF=4;
  while (1) {
//FRECUENCIA EN 6K
		frecuenciaspwm(contadorF);
		
// ESTADO INICIAL
	idle();

    // Leer entradas
    estado_act0 = (GPIOA->IDR & (1 << 0)) ? 1 : 0; //boton de grabar
		estado_act3 = (GPIOA->IDR & (1 << 3)) ? 1 : 0; //boton de leer todo
		estado_act4 = (GPIOA->IDR & (1 << 4)) ? 1 : 0; //boton de leer mientras
		estado_act5 = (GPIOA->IDR & (1 << 5)) ? 1 : 0; //boton de leer calibracion
		
// GRABAR TODA LA MEMORIA
    if (estado_act0 == 1) {
        led0 ^= 1;
        while (led0) {
            tope_mem = (GPIOA->IDR & (1 << 2)) ? 1 : 0;
            if (tope_mem) {
                break;
            }
						grabar();
            delay(100000); // Delay dentro de la secuencia
        }
       
    }
		
//LEER TODA LA MEMORIA
    if (estado_act3 == 1) {
        led1 ^= 1;
        while (led1) {
            tope_mem = (GPIOA->IDR & (1 << 2)) ? 1 : 0;
            if (tope_mem) {
                break;
            }
						conteo_frecuencia(contadorF);
						leer();
            delay(100000); // Delay dentro de la secuencia
        }
       
    }
		
		
//LEER MIENTRAS SE PRESIONA
    if (estado_act4 == 1) {
        while (estado_act4) {
            // Si PA2 está en alto
            estado_act4 = (GPIOA->IDR & (1 << 4)) ? 1 : 0;
            if (estado_act4==0) {
                break;
            }
						conteo_frecuencia(contadorF);
						leer();
            delay(100000); // Delay dentro de la secuencia
        }
        
    }
		
//MODO CALIBRACION
    if (estado_act5 == 1) {
        while (estado_act5) {
            // Si PA2 está en alto
            estado_act5 = (GPIOA->IDR & (1 << 5)) ? 1 : 0;
            if (estado_act5==0) {
                break;
            }
						calibrar();
            delay(100000); // Delay dentro de la secuencia
        }
        
    }


    delay(1000); // Pequeño delay para rebote
}
}
