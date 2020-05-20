#include "Tipos.h"
void hardcodearTipos(eTipo tipos[])
{
    char tipo[CANT][10] = {"Gamer","Disenio","Ultrabook","Normalita"};

    for ( int i = 0; i < CANT; i++ )
    {
        strcpy(tipos[i].descripcion, tipo[i]);
        tipos[i].id = cargarIDTipos();
        tipos[i].isEmpty = LLENO;
    }
}

int cargarIDTipos (void)
{
    static int idTipo = 5000;

    idTipo++;
    return idTipo;
}




void mostrarTipos(eNotebook unaNotebook[], eTipo unTipo[], int tam)
{
    int vandera = VACIO;
    int prueba = 0;

    for (int i = 0; i < tam; i++)
    {
        if(unTipo[i].isEmpty == LLENO)
        {
            printf("%10d %20s\n",unTipo[i].id,unTipo[i].descripcion);
        }
    }

    for (int i = 0; i < tam; i++)
    {
        if(unaNotebook[i].isEmpty == LLENO)
        {
            printf("%10d %20s\n",unaNotebook[i].tipoDescripcion.id,unaNotebook[i].tipoDescripcion.descripcion);
            vandera = LLENO;
        }
    }

    if(vandera == VACIO && prueba == 0)
    {
        printf("No hay tipos que listar...\n\n");
    }
}
