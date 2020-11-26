/*
    EJERCICIO 45:

    La lista creada en el ejercicio 44 es procesada por el depósito. 
    Para dicha tarea se pide hacer un programa que:

    Descuente las cantidades solicitadas del archivo de stock, creado 
    en el Ejercicio 41.
    
    Hacer una cola con los repuestos en los que no se encontró stock 
    suficiente para poder notificar a los clientes la demora de la 
    reparación.
*/

#include "../libs/libs.h"

int main (void){
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


    //inicio 45:
    long PartNumber;
    int cantidad, cantidadSolicida;
    cola_t *inicioCola = NULL, *finCola = NULL;
    extraccionRepuestos_t datoExtraido;
    while(extracInicio){
        printf("\nNumero de Parte del Producto: %d ", extracInicio->dato.repuesto.modelo);
        printf("\nCantidad del Producto: %d ", extracInicio->dato.cantidad);
        printf("\nCliente: %d ", extracInicio->dato.repuesto.cliente);
        
        PartNumber = (long)(extracInicio->dato.repuesto.modelo);
        cantidadSolicida = extracInicio->dato.cantidad;

        cantidad = lecturaDeArchivo(PartNumber); 
        printf("\nCantidad: %d", cantidad);

        if(cantidadSolicida <= cantidad){
            printf("\nHay stock suficiente");
            bajaFisica(cantidadSolicida, PartNumber);
        }
        else{
            printf("\nNo hay stock suficiente");
            datoExtraido = extracInicio->dato;
            encolar(datoExtraido, &inicioCola, &finCola);
            impresionDeCola(inicioCola);
        }
       extracInicio = extracInicio->prox; 
    }
    cantidad = lecturaDeArchivo(1);
    printf("\nCantidad: %d", cantidad);
    return 0;
}
