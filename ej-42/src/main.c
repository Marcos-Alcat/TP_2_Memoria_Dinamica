/*
    EJERCICIO 42:

    El proveedor de repuestos de CosmeFulanito informó que una 
    partida de repuestos salió con falla y debe ser devuelta. Para 
    identificar la partida, el proveedor indicó que la falla fue 
    en el partNumber: 1234 que tiene números de serie con el 
    bit 3 y 5 en 1.

    Para estas tareas se solicita:

        Hacer una cola con todos los registros fallados
        Realizar la baja física a todos los repuestos fallados
        Crear un archivo donde se vuelque el contenido de la cola en orden inverso.
        
*/

#include "../libs/libs.h"

int main (void){
    cola_t *inicio=NULL, *fin=NULL;
    leerArchivo(&inicio, &fin);
    cargaEnArchivo(&fin);
    printf("\n Fin del programa");
    return 0; 
}