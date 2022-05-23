#include <stdio.h>
#include <stdlib.h>

#include "informes.h"
#include "empresa.h"
#include "micro.h"
#include "tipo.h"
#include "validaciones.h"
#include "viaje.h"

int submenuInformes()
{
    int opcion;
    system("cls");
    printf("*** Elija una opcion para informar ***\n");
    printf("1- Mostrar micros por empresa seleccionada\n");
    printf("2- Mostrar micros por tipo seleccionado\n");
    printf("3- Promedio micros Vip\n");
    printf("4- Listar micros por empresa\n");
    printf("5- Empresas que pueden trasportar mas pasajeros\n");
    printf("6- Empresa menor cantidad de micros\n");
    printf("7- Salir\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);
    return opcion;
}

int mostrarEmpresaElegida(eMicro micros[], int tam, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT, eChofer choferes[], int tamC)
{
    int todoOk = 0;
    int idEmpresa;
    int flag=0;
    char descripcion[20];

    if(micros!=NULL && tam>0 && empresas!=NULL && tamE>0)
    {
        system("cls");
        printf("  ***Listado de micros de una empresa***\n");
        printf("------------------------------------------\n");
            listarEmpresas(empresas, tamE);
            printf("Ingrese Id de la empresa: ");
            scanf("%d", &idEmpresa);
            while(!validarEmpresa(empresas, tamE, idEmpresa))
                {
                    printf("Id empresa invalido. Reingrese el id: ");
                    scanf("%d", &idEmpresa);
                }
                for(int i=0; i<tam; i++)
                {
                    if(micros[i].isEmpty==0 && micros[i].idEmpresa==idEmpresa)
                    {
                        mostrarMicro(micros[i], empresas,tamE, tipos, tamT, choferes, tamC);
                        flag=1;
                    }
                }
                if(flag==0)
                {
                    cargarDescripcionEmpresa(empresas, tamE, idEmpresa, descripcion);
                    printf("No hay micros de la empresa %s\n", descripcion);
                }
                printf("\n\n");

        todoOk = 1;
    }
    return todoOk;
}

int mostrarTipoElegido(eMicro micros[], int tam, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT, eChofer choferes[], int tamC)
{
    int todoOk = 0;
    int idTipo;
    int flag=0;
    char descripcion[20];

    if(micros!=NULL && tam>0 && tipos!=NULL && tamT>0)
    {
        system("cls");
        printf("  ***Listado de micros de una empresa***\n");
        printf("------------------------------------------\n");
            listarTipos(tipos, tamT);
            printf("Ingrese Id del tipo: ");
            scanf("%d", &idTipo);
            while(!validarTipo(tipos, tamT, idTipo))
                {
                    printf("Id invalido. Reingrese el id: ");
                    scanf("%d", &idTipo);
                }
                for(int i=0; i<tam; i++)
                {
                    if(micros[i].isEmpty==0 && micros[i].idTipo==idTipo)
                    {
                        mostrarMicro(micros[i], empresas, tamE, tipos, tamT, choferes, tamC);
                        flag=1;
                    }
                }
                if(flag==0)
                {
                    cargarDescripcionTipo(tipos, tamT, idTipo, descripcion);
                    printf("No hay micros del tipo %s\n", descripcion);
                }
                printf("\n\n");

        todoOk = 1;
    }
    return todoOk;
}

int informarMicrosXEmpresa(eMicro micros[], int tam, eTipo tipos[], int tamT, eEmpresa empresas[], int tamE, eChofer choferes[], int tamC)
{
    int todoOk=0;
    int flag;
    if(micros!=NULL && empresas!=NULL && tamE>0 && tamT>0)
    {
        system("cls");
        printf("     **Listado de empleados por empresa***\n");
        printf("------------------------------------------------------\n");
        printf("   ID        Empresa      Tipo    Capacidad\n");
        printf("------------------------------------------------------\n");

        for(int e=0; e<tamE; e++)
        {
            printf("Empresa: %s\n", empresas[e].descripcion);

            flag=1;
            for(int i=0; i<tam; i++)
            {
                if(!micros[i].isEmpty && micros[i].idEmpresa==empresas[e].id)
                {
                    mostrarMicro(micros[i], empresas, tamE, tipos, tamT, choferes, tamC);
                    flag=0;
                }
            }
            if(flag)
            {
                printf("No hay micros de esta empresa\n");
            }
            printf("\n\n");
        }

        todoOk=1;
    }
    return todoOk;
}

int promedioVip(eMicro micros[], int tam, eTipo tipos[], int tamT, int idTipo, float* pPromedio)
{
    int todoOk=0;
    float promedio=0;
    float acumuladorVip=0;
    int contadorMicros=0;

    if(micros!=NULL && tipos!=NULL && pPromedio!=NULL && tam>0 && tamT>0 && validarTipo(tipos, tamT, idTipo))
    {
        for(int i=0; i<tam; i++)
        {
            if(!micros[i].isEmpty && micros[i].idTipo==idTipo)
            {
                contadorMicros++;
            }
            else
            {
                if(!micros[i].isEmpty && micros[i].idTipo==5003)
                {
                    contadorMicros++;
                    acumuladorVip++;
                }
            }
        }
        if(contadorMicros!=0)
        {
            promedio=acumuladorVip/contadorMicros;
        }
        *pPromedio=promedio;

        todoOk=1;
    }
    return todoOk;
}

int promedioVipEmpresa(eMicro micros[], int tam, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT)
{
    int todoOk = 0;
    int idEmpresa;
    int idTipo;
    char descripcionE[20];
    char descripcionT[20];
    float promedio;

    if(micros != NULL && tam > 0 && empresas!=NULL && tamE>0)
    {
        system("cls");
        printf("  ***Promedio de micros Vip de una empresa***\n");
        printf("-----------------------------------------------\n");

        listarEmpresas(empresas, tamE);

        printf("Ingrese Id de la empresa: ");
        scanf("%d", &idEmpresa);
            while(!validarEmpresa(empresas, tamE, idEmpresa))
                {
                    printf("Id invalido. Reingrese el id: ");
                    scanf("%d", &idEmpresa);
                }
        promedioVip(micros, tam, tipos, tamT, &idTipo, &promedio);
        cargarDescripcionEmpresa(empresas, tamE, idEmpresa, descripcionE);
        printf("Promedio de micros vip de la empresa %s: %.2f\n", descripcionE, promedio);
        todoOk = 1;
    }
    return todoOk;
}

int empresaMayorCapacidad(eMicro micros[], int tam, eEmpresa empresas[], int tamE)
{
    int todoOk=0;
    float capacidadTotal[tamE];
    float mayor;
    int flag=1;
        if(micros!= NULL && tam>0 && empresas!=NULL && tamE>0)
        {
            system("cls");
            printf("       ***Empresa de mayor capacidad***\n");
            printf("------------------------------------------\n");
            for(int i=0; i<tamE; i++)
            {
                capacidadTotal[i]=0;
            }
        }
        for(int e=0; e<tamE; e++)
        {
            for(int m=0; m<tam; m++)
            {
                if(!micros[m].isEmpty && micros[m].idEmpresa==empresas[e].id)
                {
                    capacidadTotal[e]+=micros[m].capacidad;
                }
            }
        }
        for(int e=0; e<tamE; e++)
        {
            if(flag==1 || capacidadTotal[e]>mayor)
            {
                mayor=capacidadTotal[e];
                flag=0;
            }
        }
        for(int e=0; e<tamE; e++)
        {
            if(capacidadTotal[e]==mayor)
            {
                printf("%s\n", empresas[e].descripcion);
            }
            todoOk=1;
        }
         printf("La empresa de mayor capacidad es: ", empresas->descripcion);
    return todoOk;
}

int empresaMenosMicros(eMicro micros[], int tam, eEmpresa empresas[], int tamE)
{
    int todoOk=0;
    int flag=1;
    int cantidad;
    int menor;
    int cantidadTotal[tamE];

    if(micros!=NULL && empresas!=NULL && tam>0 && tamE >0)
    {
        for(int e=0; e<tamE; e++)
        {
            cantidad=0;

            for(int i=0; i<tam; i++)
            {
                if(!micros[i].isEmpty && micros[i].idEmpresa==empresas[e].id)
                {
                    cantidad++;
                }
            }
        }
    }

    if(micros!= NULL && tam>0 && empresas!=NULL && tamE>0)
        {
            for(int i=0; i<tamE; i++)
            {
                cantidadTotal[i]=0;
            }
        }
        for(int e=0; e<tamE; e++)
        {
            for(int m=0; m<tam; m++)
            {
                if(!micros[m].isEmpty && micros[m].idEmpresa==empresas[e].id)
                {
                    cantidadTotal[e]+=cantidad;
                }
            }
        }
        for(int e=0; e<tamE; e++)
        {
            if(flag==1 || cantidadTotal[e]<menor)
            {
                menor=cantidadTotal[e];
                flag=0;
            }
        }
        for(int e=0; e<tamE; e++)
        {
            if(cantidadTotal[e]== menor)
            {
                cantidadTotal[e]=menor;
            }
            todoOk=1;
        }
         printf("La empresa con menor cantidad de micros es: %s\n", empresas->descripcion);
    return todoOk;

}
