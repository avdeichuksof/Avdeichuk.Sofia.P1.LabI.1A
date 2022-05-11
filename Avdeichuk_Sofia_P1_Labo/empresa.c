#include <stdio.h>
#include <stdlib.h>
#include "empresa.h"
#include <string.h>


int listarEmpresas(eEmpresa empresas[], int tam)
{
    int todoOk = 0;

    if(empresas!= NULL && tam>0){
        system("cls");
        printf("*** Lista de Empresas ***\n");
        printf("  Id    Descripcion\n");
        printf("-----------------------\n");
        for(int i=0; i < tam; i++){
            printf("   %4d    %10s\n", empresas[i].id, empresas[i].descripcion);
        }
        printf("\n\n");
        todoOk = 1;
    }
 return todoOk;
}

int buscarEmpresa(eEmpresa empresas[], int tam, int id, int* pIndice)
{
    int todoOk=0;
    if(empresas!=NULL && tam>0, pIndice!=NULL)
    {
        *pIndice=-1; // si da -1 no existe la empresa
        for(int i=0; i<tam;i++)
        {
            if(empresas[i].id==id)
            {
                *pIndice=i;
                break;
            }
        }
        todoOk=1;
    }
    return todoOk;
}

int cargarDescripcionEmpresa(eEmpresa empresas[], int tam, int id, char descripcion[])
{
    int todoOk = 0;
    int indice;

    buscarEmpresa(empresas, tam, id, &indice);

    if(descripcion != NULL && indice!=-1)
        {
            strcpy(descripcion, empresas[indice].descripcion);
            todoOk = 1;
        }
  return todoOk;
}
