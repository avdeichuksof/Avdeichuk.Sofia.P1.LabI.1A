#include <stdio.h>
#include <stdlib.h>
#include "chofer.h"

int inicializarChofer(eChofer choferes[], int tam)
{
    int todoOk = 0;
    if(choferes != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            choferes[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

int buscarChofer(eChofer choferes[], int tam,int id, int* pIndex)
{
    int todoOk=0;
    if(choferes!=NULL && tam>0 && pIndex!=NULL)
    {
        *pIndex=-1;
        for(int i=0; i<tam;i++)
        {
            if(choferes[i].id==id)
            {
                *pIndex=i;
                break;
            }
        }
        todoOk=1;
    }
    return todoOk;
}

int listarChoferes(eChofer choferes[], int tam)
{
    int todoOk = 0;

    if(choferes!= NULL && tam>0){
        system("cls");
        printf("      *** Lista de Choferes ***\n");
        printf("    Id      Nombre     Sexo\n");
        printf("------------------------------------\n");
        for(int i=0; i < tam; i++){
            printf("   %4d    %10s    %c\n", choferes[i].id, choferes[i].nombre, choferes[i].sexo);
        }
        printf("\n\n");
        todoOk = 1;
    }
 return todoOk;
}

int cargarDescripcionChofer(eChofer choferes[], int tam, int id, char nombre[])
{
    int todoOk = 0;
    int indice;

    buscarChofer(choferes, tam, id, &indice);

    if(nombre != NULL && indice!=-1)
        {
            strcpy(nombre, choferes[indice].nombre);
            todoOk = 1;
        }
  return todoOk;
}
