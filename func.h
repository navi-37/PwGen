#ifndef FUNC_H
#define FUNC_H

#define PW_MIN_LEN 4
#define PW_MAX_LEN 128
#define ASCII_MIN_SIMBOLO 33
#define ASCII_MAX_SIMBOLO 126
#define ASCII_MIN_NUMERO 48
#define ASCII_MIN_LETRA_MAYUSCULA 65
#define ASCII_MIN_LETRA_MINUSCULA 97

int tipo_de_pw();
int cantidad_caracteres();
void generar_pw(int tipo, int cant_car, char pw[]);
void opciones(int tipo, int bandera, char pw[], int cant_car);
void printpw(char password[]);
void copyToClipboard(const char *password);

#endif 
