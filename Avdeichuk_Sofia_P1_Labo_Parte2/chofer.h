#ifndef CHOFER_H_INCLUDED
#define CHOFER_H_INCLUDED

typedef struct
{
    int id;
    char nombre[20];
    char sexo;
    int isEmpty;
}eChofer;

#endif // CHOFER_H_INCLUDED

int buscarChofer(eChofer choferes[], int tam,int id, int* pIndex);
int listarChoferes(eChofer choferes[], int tam);
int buscarChofer(eChofer choferes[], int tam,int id, int* pIndex);
int cargarDescripcionChofer(eChofer choferes[], int tam, int id, char nombre[]);
