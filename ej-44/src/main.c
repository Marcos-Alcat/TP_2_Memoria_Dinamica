/*
   EJERCICIO 44:

   El servicio técnico utiliza la pila generada en el ejercicio 43 en su 
   labor diaria. Cada técnico toma una tarea de la pila y genera un orden 
   de extracción de repuestos al depósito. Para optimizar los viajes 
   al depósito se arma una lista con los repuestos que cada orden 
   necesita utilizando la siguiente estructura:

        typedef struct{
            repuestos_t repuesto;        
            int cantidad;
        }extraccionRepuestos_t;

    Se pide cargar la lista de repuestos solicitados por los técnicos. 
    Tener en cuenta que varios técnicos pueden necesitar la misma 
    parte, y en esos casos se debe incrementar la cantidad pedida en la 
    lista.

*/

#include "../libs/libs.h"

int main(void){
    lista_t *inicio = NULL;
    pila_t *ultimo = NULL;
    extraccionLista_t *extracInicio = NULL;
    extraccionRepuestos_t aux;
    while(continuar()){
        lista(cargar(),&inicio);
    }    
    while(inicio){
        ultimo = pila(inicio->dato,&ultimo);
        inicio = inicio->prox;
    }
    while(ultimo){
        printf ("\nModelo: %s \t Numero de Orden: %ld \t Falla: %s \t Cliente: %s \t  Fecha: %s \t Hora: %s", ultimo->dato.modelo, ultimo->dato.numeroDeOrden, ultimo->dato.descripciondeFalla, ultimo->dato.cliente, ultimo->dato.fecha, ultimo->dato.hora);
        printf("\nCantidad:\t");
        scanf("%d", &aux.cantidad);
        aux.repuesto = ultimo->dato;
        extraccion(aux, &extracInicio);
        ultimo = ultimo->siguiente;
    }
    imprimeExtracLista(extracInicio);
    return 0;
}