#include <stdio.h>
#include <stdlib.h>

#include "validaciones.h"
#include "empresa.h"
#include "tipo.h"
#include "destino.h"

int validarEmpresa(eEmpresa empresas[], int tam, int id)
{
    int esValido=0;
    int indice;

    buscarEmpresa(empresas, tam, id, &indice);
    if(indice!=-1)
    {
        esValido=1;
    }
    return esValido;
}

int validarTipo(eTipo tipos[], int tam, int id)
{
    int esValido=0;
    int indice;

    buscarTipo(tipos, tam, id, &indice);
    if(indice!=-1)
    {
        esValido=1;
    }
    return esValido;
}

int validarDestino(eDestino destinos[], int tam, int id)
{
    int esValido=0;
    int indice;

    buscarDestino(destinos, tam, id, &indice);
    if(indice!=-1)
    {
        esValido=1;
    }
    return esValido;
}

int validarMicro(eMicro micros[], int tam, int id)
{
    int esValido=0;
    int indice;

    buscarMicro(micros, tam, id, &indice);
    if(indice!=-1)
    {
        esValido=1;
    }
    return esValido;
}
