#include "uart.h"
#include "MKL25Z4.h"

#define HC05_TEST "AT"
#define HC05_VELCOM "AT+UART=9600,0,0"
#define HC05_VERSION "AT+VERSION"
#define HC05_PIN "AT+PSWD="1212""

int main(){
    uart0_init();
    uart0_send(HC05_TEST); //verifica si responde a comandos
    uart0_send(HC05_VELCOM); //9600 baudios sin paridad
    uart0_send(HC05_VERSION); //Version
    uart0_send(HC05_PIN); //PIN emparejamiento

    while(1){
        //bloque de codigo
        //a programar
    }    
}