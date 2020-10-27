/*
EJERCICIO 40:

Utilizando el archivo “potencia.dat” creado en el Ejercicio 39, realizar una 
función que pase como parámetro, entre otros datos, la clave del registro (id).

La función ubicará el registro correspondiente al id pasado como parámetro, 
y utilizando punteros imprimirá la primera palabra del campo "desc" en forma 
inversa, además cambiará el estado del bit 3 para luego actualizar el 
archivo. Además, se agregará a una pila la potencia cuando los bits 0 y 2, 
del campo estado, estén encendidos, en caso contrario se agregará el 
registro al archivo “salida.dat” de organización secuencial.
*/
#include "../libs/libs.h"


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


carga_t lecturaDelArchivo (long ID){
    FILE *fp;
    carga_t datosleidos;

    fp = fopen("potencia.dat", "rb+");
	if (fp == NULL){
		printf ("Error en la apertura");
	}

    fseek(fp,(ID)*sizeof(carga_t), SEEK_SET); 
    fread (&datosleidos, sizeof(carga_t), 1, fp);
    printf("\nOriginal\n");
    printf ("ID: %d\t Desc: %s\t Potencia: %d\t Estado: %d \t Baja/Alta: %c\n",  datosleidos.id, datosleidos.leidos.desc ,datosleidos.leidos.potencia, datosleidos.leidos.estado, datosleidos.estado);

    fclose(fp);
	return datosleidos;
}

void actualizacionDelArchivo (long ID, carga_t dato){
    FILE *fp;
    carga_t datosleidos = dato;

    fp = fopen("potencia.dat", "rb+");
	if (fp == NULL){
		printf ("Error en la apertura");
	}
    else{
    fseek(fp,(ID)*sizeof(carga_t), SEEK_SET); 
    fwrite (&datosleidos, sizeof(carga_t), 1, fp);
    fclose(fp);
    }

}

void lecturaDelArchivoActualizado (){
    FILE *fp;
    carga_t datosleidos;

    fp = fopen("potencia.dat", "rb+");
	if (fp == NULL){
		printf ("Error en la apertura");
	}
    else{
        printf("\nActualizados\n");
        fseek(fp,0L, SEEK_SET); 
        
        while (!feof(fp)){
            fread (&datosleidos, sizeof(carga_t), 1, fp);
            printf ("ID: %d\t Desc: %s\t Potencia: %d\t Estado: %d \t Baja/Alta: %c\n",  datosleidos.id, datosleidos.leidos.desc ,datosleidos.leidos.potencia, datosleidos.leidos.estado, datosleidos.estado);
        }
        fclose(fp);
    }
    
	
}


char* inversionDePalabra (carga_t dato){
    char palabra[60] = " ";
    int i = 0;
    while((dato.leidos.desc[i] != ' ') && (dato.leidos.desc[i] != '\0')){
        palabra[i] = dato.leidos.desc[i];
        i++;
    }
    return strrev(palabra);
}

void nuevoArchivoSalida (carga_t datos){
    FILE *fp;

    fp = fopen("salida.dat", "rb+");
    
    if (fp == NULL){
		printf ("Error en la apertura");
        fp = fopen("salida.dat", "wb+");
	}

	if (fp == NULL){
		printf ("Error en la apertura");
	}
    else{
        printf ("\nID: %d\t Desc: %s\t Potencia: %d\t Estado: %d \t Baja/Alta: %c\n",  datos.id, datos.leidos.desc ,datos.leidos.potencia, datos.leidos.estado, datos.estado);
        fwrite(&datos,sizeof(carga_t),1,fp);
        fclose(fp);
    }
}

void apilar (carga_t dato, pila_t **inicio, pila_t **fin){ 
    if ((dato.leidos.estado & (1 << 0)) && (dato.leidos.estado  & (1 << 2))){
        pila_t *aux;
        aux = (pila_t *)malloc(sizeof(pila_t));
        aux->pPotencia = dato.leidos.potencia; 
        aux->prox = NULL;
    
        if((*inicio) == NULL){ 
            aux->prox = (*inicio);
            (*inicio) = (*fin) = aux;
            (*inicio)->ant = NULL; 
        }

        else{
            (*fin)->prox = aux;
            aux->ant = (*fin);
            aux->prox = NULL;
            (*fin) = aux;
        }
    }else{
        nuevoArchivoSalida(dato);
    }
}

int main(void){
    long id;
    carga_t dato;
    pila_t *inicio = NULL, *fin = NULL;

    do{ 
    printf ("Ingrese ID: ");
    scanf("%ld",&id);
    dato = lecturaDelArchivo(id);
    strcpy(dato.leidos.desc, inversionDePalabra(dato)); 
    toggleBit(dato.leidos.estado,2);
    apilar(dato, &inicio, &fin);
    actualizacionDelArchivo (id,dato);
    }while(continuar());

    return 0;
}