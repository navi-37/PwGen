#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
//#include <Windows.h>
#include "func.h"

int tipo_de_pw(){
    int tipo;
    int resultado;
    //system("cls"); // windows
    system("clear"); // linux
    printf("*** Generador de contraseñas ***\n\n");
    printf("Tipo de contraseña:\n");
    printf("\n1 - Simbolos, letras y numeros\n2 - Solo numeros\n3 - Solo letras\n4 - Letras y numeros\n5 - Salir\n\n");
    do {
        resultado = scanf("%d", &tipo);

        if (resultado == 0) { // si la entrada no es un número
            printf("Entrada incorrecta, ingrese un número entre 1 y 5.\n");
            while (getchar() != '\n'); // limpiar buffer
        } else if (tipo < 1 || tipo > 5) {
            printf("Opción fuera de rango, ingrese un número entre 1 y 5.\n");
        }
    } while (resultado == 0 || tipo < 1 || tipo > 5);

    return tipo;
}

int cantidad_caracteres(){
    int cant_car;
    int resultado;

    printf("Ingresar el largo de la contraseña a generar (entre 4 y 128):\n");

    do {
        resultado = scanf("%d", &cant_car);

        if (resultado == 0) { // Si la entrada no es un número
            printf("Entrada incorrecta, ingresar un número entero entre 4 y 128.\n");
            while (getchar() != '\n'); // Limpiar buffer
        } else if (cant_car < PW_MIN_LEN || cant_car > PW_MAX_LEN) {
            printf("El valor debe estar entre 4 y 128.\n");
        }
    } while (resultado == 0 || cant_car < PW_MIN_LEN || cant_car > PW_MAX_LEN);

    return cant_car;
}

void generar_pw(int tipo, int cant_car, char password[]) {
    for (int i = 0; i < cant_car; i++) {
        switch (tipo) {
            case 1: // letras, números y símbolos
                password[i] = (rand() % (ASCII_MAX_SIMBOLO - ASCII_MIN_SIMBOLO + 1)) + ASCII_MIN_SIMBOLO;
                break;
            case 2: // solo números
                password[i] = (rand() % 10) + ASCII_MIN_NUMERO;
                break;
            case 3: // solo letras
                password[i] = (rand() % 26) + ((rand() % 2) ? ASCII_MIN_LETRA_MAYUSCULA : ASCII_MIN_LETRA_MINUSCULA);
                break;
            case 4: // letras y números
                if (rand() % 2) {
                    password[i] = (rand() % 10) + ASCII_MIN_NUMERO;
                } else {
                    password[i] = (rand() % 26) + ((rand() % 2) ? ASCII_MIN_LETRA_MAYUSCULA : ASCII_MIN_LETRA_MINUSCULA);
                }
                break;
        }
    }
    password[cant_car] = '\0'; // Agregar terminador de cadena
}

void printpw(char password[]) {
    printf("\n%s\n", password);
}

void copyToClipboard(const char *password) {
    
    // verificar si xclip está instalado en el sistema
    if (system("which xclip > /dev/null 2>&1") != 0) {
        printf("\nError: xclip no está instalado. Instálalo con 'sudo apt install xclip'\n");
        return;
    }

    FILE *pipe = popen("xclip -selection clipboard", "w");
    if (pipe == NULL) {
        perror("popen");
        return;
    }
    fprintf(pipe, "%s", password);
    pclose(pipe);

    printf("\nContraseña copiada al portapapeles.");
    printf("\nPresionar enter para continuar\n\n");

    while (getchar() != '\n'); // Limpiar buffer
    getchar();
}
/*
void copyToClipboard(const char* password){
    if (!OpenClipboard(NULL)) {
        fprintf(stderr, "Error opening clipboard.\n");
        return;
    }

    HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, (strlen(password) + 1) * sizeof(char));
    if (hMem == NULL) {
        fprintf(stderr, "Error allocating memory.\n");
        CloseClipboard();
        return;
    }

    char* pClipboardData = (char*)GlobalLock(hMem);
    if (pClipboardData == NULL) {
        fprintf(stderr, "Error locking memory.\n");
        GlobalFree(hMem);
        CloseClipboard();
        return;
    }

    strcpy(pClipboardData, password);
    GlobalUnlock(hMem);

    EmptyClipboard();
    SetClipboardData(CF_TEXT, hMem);

    CloseClipboard();
    printf("\n\nPw copiada prro\n");
    printf("\nIngresar cualquier caracter para continuar\n\n");
    fflush(stdin);
    char cont;
    scanf("%c", &cont);
}
*/