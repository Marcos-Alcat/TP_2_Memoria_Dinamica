/*
EJERCICIO 35:
Hacer un programa que tome los datos de contacto de una persona (Nombre, Apellido, edad, teléfono, mail) y los cargue, en forma directa, 
en una pila de memoria dinámica. Imprimir en pantalla y cargar en un archivo llamado "contactos.dat", de organización secuencial, los registros 
ingresados por el usuario si la persona tiene una edad mayor a 21 años.
*/

#include "../libs/libs.h"


misDatos_t cargar(void);
int continuar(void);
pila_t* apilar(misDatos_t ,pila_t**);
void archivoCargar(pila_t**);


int main(void) {

    misDatos_t cargado;
    pila_t *ultimo=NULL;

    while(continuar()){
        cargado = cargar();
        ultimo = apilar(cargado,&ultimo);
    }

    archivoCargar(&ultimo);


    return 0;
}







int continuar(void){
   int opcion = 0;
   printf("\n Cuntinuar: 1");
   printf("\n     Salir: 0");
   printf("\n    Opcion: ");
   fflush(stdin);
   scanf("%d",&opcion);
   fflush(stdin);
   if(opcion) return 1;
   else return 0;
}

misDatos_t cargar(void){
    misDatos_t cargado;
    printf("\n Nombre:");
    scanf("%s",&cargado.nombre);
    fflush(stdin);
    printf(" Apellido:");
    scanf("%s",&cargado.apellido);
    fflush(stdin);
    printf(" Edad:");
    scanf("%d",&cargado.edad);
    fflush(stdin);
    printf(" Telefono:");
    scanf("%s",&cargado.tel);
    fflush(stdin);
    printf(" Mail:");
    scanf("%s",&cargado.mail);
    fflush(stdin);
    return cargado;
}

pila_t* apilar(misDatos_t cargado,pila_t **ultimo){
    pila_t *aux = NULL; //inicializo en null.
    aux=(pila_t *) malloc(sizeof(pila_t)); //recerbo memoria.
    //cargo datos
    strcpy(aux->dato.nombre, cargado.nombre); 
    strcpy(aux->dato.apellido, cargado.apellido);
    strcpy(aux->dato.mail, cargado.mail);
    aux->dato.edad = cargado.edad;
    strcpy(aux->dato.tel, cargado.tel);
    //termino carga de datos.

    aux->siguiente = *ultimo; //sig de aux apunta al ahora anteultimo.
    return aux;
}

void archivoCargar(pila_t **ultimo){
    FILE *fp;
    pila_t *p= NULL, *aux= NULL;

    fp = fopen ("contactos.dat", "wb+"); 
    if (fp == NULL) 
    { 
        printf("\n Error");
        exit (1);
    } 
    printf("\n\n Imprimo:\n");
    p = *ultimo;
    
    while(p){
        aux=p;
        printf("\nNombre: %s",p->dato.nombre);
        printf("\nApellido: %s",p->dato.apellido);
        printf("\nEdad: %d",p->dato.edad);
        printf("\nTelefono: %s",p->dato.tel);
        printf("\nMail: %s",p->dato.mail);

        if (p->dato.edad > 21) {
            printf("\n Mayor a 21");
            fwrite(p, sizeof(struct pila_t), 1, fp);      
        }
        else {
            printf("\n Menor a 21");
        }
        p=p->siguiente;
        free(aux); 
    }
    
    fclose (fp); 
}