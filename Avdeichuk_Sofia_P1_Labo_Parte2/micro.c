#include "micro.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empresa.h"
#include "tipo.h"
#include "validaciones.h"
#include "chofer.h"

int inicializarMicros(eMicro micros[], int tam)
{
    int todoOk = 0;
    if(micros != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            micros[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

int buscarMicroLibre(eMicro micros[], int tam, int* pIndex)
{
    int todoOk = 0;
    if(micros!= NULL && tam>0 && pIndex!=NULL)
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if( micros[i].isEmpty )
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int altaMicro(eMicro micros[], int tam, int* pId, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT, eChofer choferes[], int tamC)
{
    int todoOk = 0;
    int indice;
    char auxCad[100];
    eMicro nuevoMicro;


    if(micros!=NULL && tam>0 && pId!=NULL)
    {
        if(buscarMicroLibre(micros, tam, &indice))
        {
            if(indice == - 1)
            {
                printf("No hay lugar en el sistema\n");
            }
            else
            {
                listarEmpresas(empresas, tamE);
                printf("Ingrese id de la empresa: ");
                scanf("%d", &nuevoMicro.idEmpresa);
                while(!validarEmpresa(empresas, tamE, nuevoMicro.idEmpresa))
                {
                    printf("Empresa invalida. Ingrese empresa: ");
                    scanf("%d", &nuevoMicro.idEmpresa);
                }

                listarTipos(tipos, tamT);
                printf("Ingrese el tipo: ");
                scanf("%d", &nuevoMicro.idTipo);
                while(!validarTipo(tipos, tamT, nuevoMicro.idTipo))
                {
                    printf("Tipo invalido. Ingrese tipo: ");
                    scanf("%d", &nuevoMicro.idTipo);
                }

                printf("Ingrese la capacidad: ");
                scanf("%d", &nuevoMicro.capacidad);
                while(micros[indice].capacidad<1 && micros[indice].capacidad>50)
                    {
                        printf("Capacidad invalida. Ingrese nueva capacidad (1-50): ");
                        scanf("%d", micros[indice].capacidad);
                    }

                listarChoferes(choferes, tamC);
                printf("Ingrese chofer: ");
                scanf("%d", &nuevoMicro.idChofer);
                while(micros[indice].idChofer<3000 && micros[indice].idChofer>3003)
                    {
                        printf("Id invalido. Ingrese id: ");
                        scanf("%d", micros[indice].idChofer);
                    }

                nuevoMicro.isEmpty = 0;
                nuevoMicro.id = *pId;
                *pId = *pId + 1;
                micros[indice] = nuevoMicro;
                todoOk = 1;
            }
        }
        else
        {
            printf("Ocurrio un problema con los parametros\n");
        }
    }
    return todoOk;
}

int ordenarMicrosEmpresaYCapacidad(eMicro micros[], int tam)
{
    int todoOk = 0;
    eMicro auxMicros;
    if(micros!=NULL && tam>0)
    {
        for(int i=0; i < tam -1; i++)
        {
            for(int j= i + 1; j < tam; j++)
            {
                if( ((micros[i].idEmpresa == micros[j].idEmpresa) && (micros[i].capacidad < micros[j].capacidad))
                        || ((micros[i].idEmpresa != micros[j].idEmpresa) &&(micros[i].idEmpresa < micros[j].idEmpresa)) )
                {
                    auxMicros = micros[i];
                    micros[i] = micros[j];
                    micros[j] = auxMicros;
                }
            }
        }
        todoOk = 1;
    }
}

int listarMicros(eMicro micros[], int tam, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT, eChofer choferes[], int tamC)
{
    int todoOk = 0;
    int flag=0;

    if(micros!= NULL && tam>0)
    {
        system("cls");
        printf("*** Lista de Micros ***\n");
        printf("  Id     Empresa     Tipo        Capacidad   Chofer\n");
        printf("----------------------------------------------------\n");
        for(int i=0; i < tam; i++)
        {
            if(!micros[i].isEmpty)
            {
                mostrarMicro(micros[i], empresas, tamE, tipos, tamT, choferes, tamC);
                ordenarMicrosEmpresaYCapacidad(micros, tam);
                flag++;
            }
        }
        if(flag == 0)
        {
            printf("No hay micros en el sistema");
        }
        printf("\n\n");

        todoOk = 1;
    }
    return todoOk;
}

int buscarMicro(eMicro micros[], int tam,int id, int* pIndex)
{
    int todoOk = 0;
    if(micros!=NULL && tam>0 && pIndex!=NULL && id>0)
    {
        *pIndex = -1;
        for(int i=0; i<tam; i++)
        {
            if( micros[i].isEmpty == 0 &&  micros[i].id == id )
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int menuModificarMicro()
{
   int opcion;
    system("cls");
    printf("*** Campos a modificar ***\n");
    printf("1- Tipo\n");
    printf("2- Capacidad\n");
    printf("10- Salir\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);
    return opcion;
}

int mostrarMicro(eMicro micros, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT, eChofer choferes[], int tamC)
{
    int todoOk = 0;
    char descEmpresa[20];
    char descTipos[20];
    char nombreChofer[20];

    if(empresas!= NULL && tamE> 0 && tipos!=NULL && tamT>0){

    cargarDescripcionEmpresa(empresas, tamE, micros.idEmpresa, descEmpresa);
    cargarDescripcionTipo(tipos, tamT, micros.idTipo, descTipos);
    cargarDescripcionChofer(choferes, tamC, micros.idChofer, nombreChofer);

    printf("  %4d   %10s  %10s     %2d   %10s\n", micros.id, descEmpresa, descTipos, micros.capacidad, nombreChofer);
        todoOk = 1;
    }
    return todoOk;
}

int modificarMicro(eMicro micros[], int tam, eTipo tipos[], int tamT, eEmpresa empresas[], int tamE, eChofer choferes[], int tamC)
{
    int todoOk = 0;
    int indice;
    int id;
    char salir = 'n';

    if(micros!= NULL && tam > 0)
    {
        listarMicros(micros, tam, empresas, tamE, tipos, tamT, choferes, tamC);
        printf("Ingrese Id: ");
        scanf("%d", &id);
        if(buscarMicro(micros, tam, id, &indice))
        {
            if(indice == -1)
            {
                printf("No hay un micro con Id %d\n", id);
            }
            else
            {
                listarMicros(micros, tam, empresas, tamE, tipos, tamT, choferes, tamC);
                do
                {
                    switch(menuModificarMicro())
                    {
                        case 1:
                            listarTipos(tipos, tamT);
                            printf("Ingrese nuevo tipo: ");
                            scanf("%d", &micros[indice].idTipo);
                            break;
                        case 2:
                            printf("Ingrese nueva capacidad: ");
                            scanf("%d", micros[indice].capacidad);
                            while(micros[indice].capacidad<1 && micros[indice].capacidad>50)
                            {
                                printf("Capacidad invalida. Ingrese nueva capacidad (1-50): ");
                                scanf("%d", micros[indice].capacidad);
                            }
                            break;
                        case 3:
                            salir='s';
                            break;
                    }
                system("pause");
                }while(salir!='s');
            }
        }
        else
        {
            printf("Ocurrio un problema al buscar micro\n");
        }
        todoOk=1;
    }
    return todoOk;
}

int bajaMicro(eMicro micros[], int tam, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT, eChofer choferes[], int tamC)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirmar;
    if(micros!=NULL && tam>0)
    {
        listarMicros(micros, tam, empresas, tamE, tipos, tamT, choferes, tamC);
        printf("Ingrese id: ");
        scanf("%d", &id);

        if( buscarMicro(micros, tam, id, &indice))
        {
            if(indice == -1)
            {
                printf("No hay un micro con id %d\n", id);
            }
            else
            {
                mostrarMicro(micros[indice], empresas, tamE, tipos, tamT, choferes, tamC);
                printf("Confirma baja?: ");
                fflush(stdin);
                scanf("%c", &confirmar);
                if(confirmar!='S' && confirmar!='s')
                {
                    printf("Baja cancelada por el usuario\n");
                }
                else
                {
                    micros[indice].isEmpty = 1;
                    printf("Baja realizada con el exito\n");
                    todoOk = 1;
                }
            }

        }
        else
        {
            printf("Ocurrio un problema al buscar empleado\n");
        }
        todoOk = 1;
    }
    return todoOk;
}


