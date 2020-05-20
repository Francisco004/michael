#ifndef TRABAJOS_H_INCLUDED
#define TRABAJOS_H_INCLUDED
#include "Notebook.h"
#include "Fecha.h"
typedef struct
{
    int id;
    int isEmpty;
    int idNotebook;
    int idServicio;
    eFecha fecha;

}eTrabajo;

/** \brief Asigna una id a trabajos
 *
 * \param
 * \param
 * \return La id autoincremental
 *
 */
int cargarIDTrabajo (void);

/** \brief Muestra todos los trabajos
 *
 * \param unaNotebook[] eNotebook estrucura notebooks
 * \param unTrabajo[] eTrabajo estrucura trabajo
 * \param unServicio[] eServicio estrucura servicio
 * \param tam int cantidad de iteraciones
 * \return void
 *
 */
void mostrarTrabajos(eNotebook unaNotebook[], eTrabajo unTrabajo[],eServicio unServicio[], int tam);

/** \brief Da de alta un trabajo
 *
 * \param unTrabajo[] eTrabajo estructura trabajo
 * \param unaNotebook[] eNotebook estructura notebooks
 * \param tam int cantidad de iteraciones
 * \return void
 *
 */
void altaTrabajo(eTrabajo unTrabajo[], eNotebook unaNotebook[],int tam);


#endif // TRABAJOS_H_INCLUDED
