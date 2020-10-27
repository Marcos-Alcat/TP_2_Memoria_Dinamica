#ifndef LIB_H
#define LIB_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct misDatos_t {
    char nombre[20];
    char apellido[20];
    char edad;
    char tel[20];
    char mail[40];
} misDatos_t;


typedef struct pila_t {
    misDatos_t dato;
    struct pila_t *siguiente;
} pila_t;

typedef struct lista_t{
    misDatos_t dato;
    struct lista_t *prox;
}lista_t;


#endif // LIBS_H


