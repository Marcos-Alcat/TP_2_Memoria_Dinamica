#include "../libs/libs.h"

lista_t* lista(void){
    struct lista_t *pre=NULL, *r=NULL, *aux=NULL, *in=NULL; 
    struct lista_t registro; 
	misDatos_t dat;
	FILE *fp; 

    fp = fopen ("contactos.dat","rb+");
        if (!fp){
            printf("Error de apertura: %s \n","contactos.dat");
        }else{ 

        while(fread(&registro,sizeof(struct pila_t),1,fp)){
            aux=(lista_t*) malloc(sizeof(lista_t));
            aux->dato=registro.dato;
            aux->prox=NULL;

            if(in == NULL){
                in = aux;
            }
            else{
                if(0 > strcmp(aux->dato.apellido, in->dato.apellido)){ //inicio lista
                    aux->prox=in; //el proximo del reserbado en memoria sera in. 
                    in = aux;
                }
                else
                {
                    r = in; //puntero en el cual estoy
                    pre = in; //apunta al anterior al que uso para recorrer.
                    
                    while (0 <= strcmp(aux->dato.apellido, r->dato.apellido) && r->prox != NULL){ //hasta que prox sea null o el que agregue sea mayor
                        pre = r; 
                        r = r->prox; 
                    }
                    if(0 <= strcmp(aux->dato.apellido, r->dato.apellido)){ //caso para nodo en la parte central.
                        r->prox = aux;
                    }
                    else{  //en caso de estar al final.
                        aux->prox = r; 
                        pre->prox = aux; 
                    }
                }  
            }		
        }
        fclose(fp);
        }

        return in;
}

void cargarArchivo(lista_t *r){ 
    FILE *fp; 
    lista_t *b=NULL;

	fp = fopen("contactos_ordenados.dat", "wb+");
	if (!fp){
		printf("Error en la creacion del archivo %s","contactos_ordenados.dat");
	}else{ 
	
	while(r){
		fwrite(&r->dato,sizeof(struct misDatos_t),1,fp);
		b = r;
		r = r->prox;
		free(b);
	}
	fclose(fp);
    }

    }

void leerArchivo (void){
    FILE *fp;
    misDatos_t dat;
	printf("\n\nLeo archivo \n\n");
	fp = fopen("contactos_ordenados.dat", "rb+");
	if (fp == NULL){
		printf ("Error apertura ");
	}
	fseek(fp, (0L), SEEK_SET);
	fread(&dat,sizeof(struct misDatos_t),1,fp);

		while(!feof(fp)){
			printf ("Nombre: %s\t Apellido: %s\t Edad: %d\t Telefono: %s\t Mail: %s \n",  dat.nombre, dat.apellido, dat.edad, dat.tel, dat.mail);
			fread(&dat,sizeof(struct misDatos_t),1,fp);
		}
	
	fclose(fp);
}



int main(void){

    cargarArchivo(lista());
	leerArchivo();

}