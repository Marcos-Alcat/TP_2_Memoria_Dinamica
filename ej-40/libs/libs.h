#ifndef LIBS_H
#define LIBS_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define toggleBit(var,bit) var=var^(1<<bit)

typedef struct pila{
    unsigned char pPotencia;
    struct pila *prox;
    struct pila *ant;
}pila_t;

typedef struct {
    char desc[60];
    unsigned char potencia;
    unsigned int estado;
} datos_t;

typedef struct {
    datos_t leidos;
    unsigned int id;
    char estado;
}carga_t;

typedef struct lista_t{
    datos_t dato;
    struct lista_t *prox;
}lista_t;


#endif /*LIBS_H*/