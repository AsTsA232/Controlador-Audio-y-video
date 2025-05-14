/*
 * File:   Cont.c
 * Author:  María Teresa Hurtado Gallardo
 *
 * Created on April 24, 2025, 11:58 AM
 */


// CONFIG
#pragma config FOSC = INTOSCIO  // Oscillator Selection bits (INTOSC oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // RA5/MCLR/VPP Pin Function Select bit (RA5/MCLR/VPP pin function is MCLR)
#pragma config BOREN = OFF      // Brown-out Detect Enable bit (BOD disabled)
#pragma config LVP = OFF        // Low-Voltage Programming Enable bit (RB4/PGM pin has digital I/O function, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EE Memory Code Protection bit (Data memory code protection off)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)


#define _XTAL_FREQ 4000000
#include <xc.h>
int cont_frec=4;


void setupPWM(int cont)
{
    //TRISA4 = 0;  // Configurar (CCP1) como salida
    CCP1CON = 0x0C; // Configurar el modo PWM en el CCP1
    T2CONbits.TMR2ON = 1; // Encender Timer2
    CCPR1L = 2;
    
    if(cont==1){
        PR2 = 82;  //  para 3 kHz
        T2CONbits.T2CKPS = 0x01;
    }else if(cont==2){
        PR2 = 61;  //  para 4 kHz
        T2CONbits.T2CKPS = 0x01;
    }else if(cont==3){
        PR2 = 49;  //  para 5 kHz
        T2CONbits.T2CKPS = 0x01;
    }else if(cont==4){
        PR2 = 167;  //  para 6 kHz
        T2CONbits.T2CKPS = 0x00;
    }else if(cont==5){
        PR2 = 124;  //  para 8 kHz
        T2CONbits.T2CKPS = 0x00;
    }else if(cont==6){
        PR2 = 99;  //  para 10 kHz
        T2CONbits.T2CKPS = 0x00;
    }else if(cont==7){
        PR2 = 82;  //  para 12 kHz
        T2CONbits.T2CKPS = 0x00;
    }else{
        PR2=PR2;
        T2CONbits.T2CKPS = T2CONbits.T2CKPS;
    }
    
    
}

void Control_Frecuencia(){
//AUMENTO DE FRECUENCIA
       if(RA4==0&&cont_frec<8){
        cont_frec=cont_frec+1;
        setupPWM(cont_frec);
        __delay_ms(800);
        }
//DISMUNICION DE FRECUENCIA
        if(RA7==0&&cont_frec>1){
        cont_frec=cont_frec-1;
        setupPWM(cont_frec);
        __delay_ms(800);
        }
}


void main(void) {
#define XTAL_FREQ=4000000;

    //DEFINIR EL PUERTO A COMO ENTRADAS
    
    TRISA =0xFF;
    //DEFINIR PUERTO B COMO SALIDAS
    
    TRISB=0x00;
    

    
    while(1){
        PORTB=0x17; 
//PWM A 6K
    setupPWM(cont_frec);        
    //RA0 "BOTON DE GRABAR"
    //RA1 TOPE DE MEMORIA
        if(RA0==0){
            while(RA1==0){
                   
                cont_frec=4;
                PORTB=0x02;
            }
        }
//LEER TODA LA MEMORIA
        if(RA2==0){    
            while(RA1==0){
                PORTB=0x04;
//AUMENTO O DISMINUCION DE FRECUENCIA   
             Control_Frecuencia();
            }
        }
        
//LEER LA MEMORIA MIENTRAS SE PRESIONA
        while(RA3==0){
            PORTB=0x04;
            
//AUMENTO O DISMINUCION DE FRECUENCIA  
            Control_Frecuencia();
        }
} 
        
    }
    
    
