#ifndef MARCAS_H_INCLUDED
#define MARCAS_H_INCLUDED
#include "Notebook.h"
typedef struct
{
    int id;
    int isEmpty;
    char descripcion[21];

}eMarca;

/** \brief Hardcodea la estructura marcas
 *
 * \param marcas[] eMarca estructura marcas
 * \return void
 *
 */
void hardcodearMarcas(eMarca marcas[]);

/** \brief Asigna una id a marcas
 *
 * \param
 * \param
 * \return La id autoincremental
 *
 */
int cargarIDMarcas (void);


/** \brief Muestra todas las marcas
 *
 * \param unaNotebook[] eNotebook estrucura notebooks
 * \param unaMarca[] eMarca estrucura marcas
 * \param tam int cantidad de iteraciones
 * \return void
 *
 */
void mostrarMarcas(eNotebook unaNotebook[], eMarca unaMarca[], int tam);


#endif // MARCAS_H_INCLUDED
