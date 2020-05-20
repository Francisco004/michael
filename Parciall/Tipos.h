#ifndef TIPOS_H_INCLUDED
#define TIPOS_H_INCLUDED
#include "Notebook.h"
typedef struct
{
    int id;
    int isEmpty;
    char descripcion[21];

}eTipo;

/** \brief Hardcodea la estructura tipos
 *
 * \param tipos[] eTipo estructura tipos
 * \return void
 *
 */
void hardcodearTipos(eTipo tipos[]);

/** \brief Asigna una id a tipos
 *
 * \param
 * \param
 * \return La id autoincremental
 *
 */
int cargarIDTipos (void);

/** \brief Muesta todos los tipos
 *
 * \param unaNotebook[] eNotebook estrucura notebooks
 * \param unTipo[] eTipo estructura tipos
 * \param tam int cantidad de iteraciones
 * \return void
 *
 */
void mostrarTipos(eNotebook unaNotebook[], eTipo unTipo[], int tam);


#endif // TIPOS_H_INCLUDED
