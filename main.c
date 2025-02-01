#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
//#include <windows.h>
#include "func.h"

int main(){
    srand(time(NULL));
    int tipo;
    int cant_car;
    int bandera = 1;
    char pw[PW_MAX_LEN];

    while(bandera != 0){
        tipo = tipo_de_pw();
        if (tipo == 5){
            bandera = 0;
        } else{
            cant_car = cantidad_caracteres();
            generar_pw(tipo, cant_car, pw);
            printpw(pw);
            copyToClipboard(pw);
        }
    }
    return 0;
}
