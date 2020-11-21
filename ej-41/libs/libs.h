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
        }repuestos_t;

typedef struct lista_t{
    repuestos_t repuesto;
    struct lista_t *siguiente;
}lista_t;


repuestos_t cargarDatos (void);
lista_t* listar(void);
void imprimirLista (lista_t* in);
void cargaArchivo (lista_t** in);
int continuar(void);

#endif 