/*
EJERCICIO 37:
Existe un archivo llamado "datos.dat", de tipo binario, cuya organización es secuencial.
 Los datos están organizados según la siguiente estructura:
struct d{
long clave; //Clave o Id del registro
char d[30]; // Descripcion
unsigned char tipo; //Tipo de datos como entero sin signo
char b; //'A':Alta 'B':Baja
}
Se Pide: Realizar una funciún que pase como parámetro la clave, entre otros parámetros,
y apile dos valores, la Clave y su posición física respecto al archivo (registro 1, 2, etc),
si es que el campo tipo tiene el bit 4 con valor 1. En caso de no encontrarlo mostrar por pantalla
"Registro no encontrado". La función debe devolver el puntero de pila. Realizar el main con varias
llamadas a dicha función y proceder a mostrar las descripciones del archivo, mediante la pila como acceso directo,
NO USAR VARIABLES GLOBALES.
*/

#include "../libs/lib.h"


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


int cargaArchivo(){ 
    FILE *fp;
    int i, ct=0;
    struct d r;
    if ((fp = fopen("datos.dat", "wb")) == NULL){
        printf ("Error en apertura\n");
        return 1;
    }
    else {
        do{ 
            printf("\nTipo: ");
            scanf("%d",&ct); 
            r.tipo = (unsigned char)ct;
            printf("clave: ");
            scanf("%ld",&r.clave);
            r.b = 'A';
            printf("De una descripcion: ");
            scanf("%s",&(r.d)); 
            fwrite(&r, sizeof(r), 1, fp); 
        }while(continuar());

     fclose (fp);
     return 0;
    }
}


void leoArchivo(long clave, int *posicion, struct d *dato){ 
    FILE *fich;
    int check = 1; 
    (*posicion) = 1;

    if ((fich = fopen("datos.dat", "rb")) == NULL){ 
        printf ( "Error en apertura del fichero para lectura \n " );
    }
    
    else{ 
        fread (dato, sizeof(struct d), 1, fich);
        while (!feof(fich)&&(check==1)){ 
            if(clave == dato->clave && dato->b =='A'){  
                check = 0;
                fclose (fich);
                printf ("\nTipo:%d \tDescripcion:%s \tEstado:%c \tClave:%ld\n" , dato->tipo, dato->d, dato->b, dato->clave);
                break;
            }else{
            fread (dato, sizeof(struct d), 1, fich);
            }
         (*posicion)++;
        }
        if(check){
            (*posicion)=-3;
        }
        fclose (fich);
    }
}


pila_t* PILA(long clave, int posicion, struct d dato, pila_t *pila){ 
    pila_t *aux;
    pila_t * tope = pila;

    aux = NULL;

    if((posicion > 0) && (dato.tipo & (1 << 4))){
        aux=(pila_t *) malloc(sizeof(pila_t));  //OBTENEGO LUEGAR EN MEMORIA
        ///CargO DATOS
        aux->dato.clave = dato.clave;
        aux->dato.posicion = posicion;
        if(!pila){
            aux->prox = NULL;
            tope = aux;
        }else{
            aux->prox = tope;
            tope = aux;
        } 
    }
    else{
        printf("\n Registro no encontrado \n");
        
    } 
    return tope;
}

void imprimoArchivo (long pos){
    FILE *fp;
    struct d dato;

    if ((fp = fopen("datos.dat", "rb")) == NULL){
        printf ("Error en apertura\n");
    }
    else{
        fseek(fp,(pos-1)*sizeof(dato), SEEK_SET); 
        fread (&dato, sizeof(dato), 1, fp);
        printf ("\nClave:%ld \tDescripcion:%s \tEstado:%c \tTipo:%d\n" , dato.clave, dato.d, dato.b, dato.tipo);
    }
    fclose(fp);
}

int main(void) { 

    struct d dato;
    int posicion=0;
    long clave;
    pila_t *pila = NULL;
    
    //if(cargaArchivo())printf("\nError al crear Archivo\n"); //para crear el archivo en caso de no tenerlo.

    while(continuar()){
    printf("\nClave:");
    scanf("%ld",&clave);
    leoArchivo(clave, &posicion, &dato);
    pila = PILA(clave, posicion, dato, pila); 
    }
    
    printf("\nImprimo archivo:\n"); 
       while(pila!=NULL){
        imprimoArchivo(pila->dato.posicion);
        pila = pila->prox;
    }
    return 0;
}