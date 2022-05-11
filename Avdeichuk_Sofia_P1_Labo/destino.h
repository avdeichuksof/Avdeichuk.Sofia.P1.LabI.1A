#ifndef DESTINO_H_INCLUDED
#define DESTINO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[25];
    float precio;
}eDestino;

#endif // DESTINO_H_INCLUDED

/** \brief realiza un listado de los destinos
 *
 * \param destinos[] eDestino Array destinos
 * \param tam int Tamaño del array
 * \return int Devuelve el listado
 *
 */
int listarDestinos(eDestino destinos[], int tam);
int buscarDestino(eDestino destinos[], int tam, int id, int* pIndice);
int cargarDescripcionDestino(eDestino destinos[], int tam, int id, char descripcion[]);
