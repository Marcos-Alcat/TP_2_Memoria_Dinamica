#ifndef LIBS_H
#define LIBS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    long partNumber;
    long serialNumber;
    char descripcion[40];       
    char ubicacion[100];        
}repuestosEjAnterior_t;

typedef struct{
    long numeroDeOrden;
    char cliente[40];       
    char descripciondeFalla[200];        
    char modelo[65]; //es equivalente a Part Number
    char fecha[10];
    char hora[10];
}repuestos_t;

typedef struct{
    repuestos_t repuesto;        
    int cantidad;
}extraccionRepuestos_t;

typedef struct cola{
    extraccionRepuestos_t dato;        
    struct cola *prox;
    struct cola *ant;
}cola_t;

//Exclusivo del 44:

typedef struct lista_t{
    repuestos_t dato;
    struct lista_t *prox;
}lista_t;

typedef struct pila_t {
    repuestos_t dato;
    struct pila_t *siguiente;
}pila_t;


typedef struct extraccionLista_t{
    extraccionRepuestos_t dato;        
    struct plista_t *prox;
}extraccionLista_t;

//Del 45
int lecturaDeArchivo (long);
void bajaFisica (int, long);
void encolar(extraccionRepuestos_t dato,cola_t **inicio, cola_t **fin);
void impresionDeCola( cola_t *inicio);

//Del 44:
void cargaArchivo (pila_t *pila);
repuestos_t cargar(void);
void lista(repuestos_t dato,struct lista_t **in);
pila_t* pila(repuestos_t cargado,pila_t **ultimo);
void imprimeExtracLista(extraccionLista_t *r);
void extraccion(extraccionRepuestos_t dato,struct extraccionLista_t **in);
void listados(void);

#endif 
