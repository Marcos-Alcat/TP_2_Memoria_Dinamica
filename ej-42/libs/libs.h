#ifndef LIBS_H
#define LIBS_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct{
            long partNumber;
            long serialNumber;
            char descripcion[40];       
            char ubicacion[100];        
        }repuestos_t;

typedef struct cola{
    repuestos_t datos;
    struct cola *prox, *ant;
}cola_t;

void cargaEnArchivo (cola_t** fin);
void encolar(repuestos_t dato,cola_t **inicio, cola_t **fin);
void leerArchivo (cola_t **inicio, cola_t **fin);

#endif 