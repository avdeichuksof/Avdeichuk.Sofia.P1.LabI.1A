#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
}eTipo;

#endif // TIPO_H_INCLUDED

/** \brief realiza un listado de los tipos de asiento
 *
 * \param tipos[] eTipo Array tipo
 * \param tam int Tamaño del array
 * \return int Devuelve el listado
 *
 */
int listarTipos(eTipo tipos[], int tam);

int buscarTipo(eTipo tipos[], int tam, int id, int* pIndice);

int cargarDescripcionTipo(eTipo tipos[], int tam, int id, char descripcion[]);
