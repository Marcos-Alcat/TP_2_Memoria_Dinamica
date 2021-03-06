#ifndef LIBS_H
#define LIBS_H 

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct{
    long numeroDeOrden;
    char cliente[40];       
    char descripciondeFalla[200];        
    char modelo[65];
    char fecha[10];
    char hora[10];
}repuestos_t;

typedef struct lista_t{
    repuestos_t dato;
    struct lista_t *prox;
}lista_t;

typedef struct pila_t {
    repuestos_t dato;
    struct pila_t *siguiente;
}pila_t;

//44
typedef struct{
    repuestos_t repuesto;        
    int cantidad;
}extraccionRepuestos_t;

typedef struct extraccionLista_t{
    extraccionRepuestos_t dato;        
    struct extraccionLista_t *prox;
}extraccionLista_t;

void listados(void);
repuestos_t cargar(void);
void lista(repuestos_t dato,struct lista_t **inicio);
void imprimeExtracLista(extraccionLista_t *r);
void cargaArchivo (pila_t *pila);
pila_t* pila(repuestos_t cargado,pila_t **ultimo);
void extraccion(extraccionRepuestos_t dato,struct extraccionLista_t **in);

#endif 