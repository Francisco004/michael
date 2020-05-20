#ifndef NOTEBOOK_H_INCLUDED
#define NOTEBOOK_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Tipos.h"
#include "Marcas.h"
#include "Parcial.h"
#define TAM 1000
#define VACIO 0
#define LLENO 1
#define CANT 4

typedef struct
{
    int id;
    int idTipo;
    int idMarca;
    int isEmpty;
    float precio;
    char modelo[21];
    eTipo tipoDescripcion;
    eMarca marcaDescripcion;

}eNotebook;


/** \brief Inicializa la estructura notebooks en datos vacios
 *
 * \param unaNotebook[] eNotebook estructura notebook
 * \param tam int cantidad de iteraciones
 * \return void
 *
 */
void inicializarNotebooks(eNotebook unaNotebook[], int tam);

/** \brief Asigna una id a notebooks
 *
 * \param void
 * \return La id autoincremental
 *
 */
int cargarIDNotebooks(void);

/** \brief Da de alta una notebook en un espacio libre
 *
 * \param unaNotebook[] eNotebook estructura notebooks
 * \param tam int cantidad de iteraciones
 * \return void
 *
 */
void alta(eNotebook unaNotebook[],int tam);

/** \brief Da de baja una notebook ingresando la id
 *
 * \param unaNotebook[] eNotebook estructura de notebooks
 * \param tam int cantidad de interaciones
 * \return void
 *
 */
void darDeBajaUnaNotebook(eNotebook unaNotebook[], int tam);

/** \brief Modifica una notebook ingresando la id
 *
 * \param unaNotebook[] eNotebook estructura de notebooks
 * \param unTipo[] eTipo estructura tipo para modificar el tipo
 * \param tam int cantidad de iteraciones
 * \return void
 *
 */
void modificarUnaNotebook(eNotebook unaNotebook[],eTipo unTipo[],int tam);

/** \brief Muestra una notebook
 *
 * \param unaNotebook eNotebook estructura notebook
 * \return void
 *
 */
void mostrarNotebook(eNotebook unaNotebook);

/** \brief  muestra una notebook pero con la ID
 *
 * \param unaNotebook eNotebook estructura notebooks
 * \return void
 *
 */
void mostrarNotebookConID(eNotebook unaNotebook);

/** \brief Muesta las notebooks ordenadas por modelo y precio
 *
 * \param unaNotebook[] eNotebook estructura notebooks
 * \param tam int
 * \return void
 *
 */
void listarNotebooks(eNotebook unaNotebook[], int tam);

/** \brief Muestra todas las notebooks
 *
 * \param unaNotebook[] eNotebook estructura notebooks
 * \param tam int
 * \return void
 *
 */
void mostrarNotebooks(eNotebook unaNotebook[], int tam);


/** \brief Busca espacio libre para la notebook
 *
 * \param unaNotebook[] eNotebook estructura notebooks
 * \param tam int cantidad de iteraciones
 * \return int la posicion donde hay espacio (ID)
 *
 */
int buscarLibre(eNotebook unaNotebook[], int tam);

/** \brief Muestra todas las notebooks segun el tipo seleccionado
 *
 * \param unaNotebook[] eNotebook estructura notebooks
 * \param tam int cantidad de iteraciones
 * \return void
 *
 */
void mostrarNotebooksPorTipo(eNotebook unaNotebook[], int tam);

/** \brief Muestra todas las notebooks segun la marca seleccionada
 *
 * \param unaNotebook[] eNotebook estructura notebooks
 * \param tam int cantidad de iteraciones
 * \return void
 *
 */
void mostrarNotebooksPorMarca(eNotebook unaNotebook[], int tam);

/** \brief Muestra la notebook mas barata
 *
 * \param unaNotebook[] eNotebook estructura notebooks
 * \param tam int cantidad de iteraciones
 * \return void
 *
 */
void mostrarNotebookMasBarata(eNotebook unaNotebook[], int tam);

/** \brief Muestra todas las notebooks por marca
 *
 * \param unaNotebook[] eNotebook estructura notebooks
 * \param tam int cantidad de iteraciones
 * \return void
 *
 */
void mostrarNotebookPorMarca(eNotebook unaNotebook[], int tam);

/** \brief Muestra una notebook seleccionando el tipo y la marca
 *
 * \param unaNotebook[] eNotebook estructura notebooks
 * \param tam int cantidad de iteraciones
 * \return void
 *
 */
void elegirTipoYMarca(eNotebook unaNotebook[], int tam);

/** \brief Muestra la marca mas elegida
 *
 * \param unaNotebook[] eNotebook estructura notebooks
 * \param tam int cantidad de iteraciones
 * \return void
 *
 */
void mostrarLaMarcaMasElegida(eNotebook unaNotebook[], int tam);


#endif // NOTEBOOK_H_INCLUDED
