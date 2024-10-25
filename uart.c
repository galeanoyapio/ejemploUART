#include "uart.h"
#include "MKL25Z4.h"

void uart0_init(){
    SIM->SCGC4|=SIM_SCGC4_UART0_MASK;
    SIM->SCGC5|=SIM_SCGC5_PORTA_MASK;
    PORTA->PCR[1]=PORT_PCR_MUX(2);//Rx
    PORTA->PCR[2]=PORT_PCR_MUX(2);//Tx
    UART0->C2=0; //Deshabilito comunicaciones por prevencion
    UART0->BDH=0x0;
    UART0->BDL=0x26; //9600 baudios
    UART0->C1=0x00; //8 bits, sin paridad
    UART0->C2=0b00001100; //Habilito comunicaciones en tx y rx
}

char uart0_recibe(){
    while(!(UART0->S1&UART_S1_RDRF_MASK)); //Espera a recibir todo
    char dato;
    return dato = UART0->D;
}

void uart0_send(char dato){
    while(!(UART0->S1&UART_S1_TDRE_MASK)); //Espera a enviar todo
    UART0->D = dato;
}