#include "Notebook.h"
#include "Parcial.h"
#include "Tipos.h"
#include "Marcas.h"
#include "Servicios.h"
#include "Trabajos.h"
#include "Fecha.h"

int main()
{

    char seguir[10];
    int banderaAlta = 0;
    int banderaAltaTrabajos = 0;

    eNotebook unaNotebook[TAM];
    eMarca unaMarca[TAM];
    eTipo unTipo[TAM];
    eServicio unServicio[TAM];
    eTrabajo unTrabajo[TAM];

    inicializarNotebooks(unaNotebook,TAM);
    hardcodearMarcas(unaMarca);
    hardcodearTipos(unTipo);
    hardcodearServicios(unServicio);
    do
    {
        system("cls");
        switch (menu())
        {
        case 1:
            ////////////////////////////////////////////////////ALTA Notebook
            system("cls");
            alta(unaNotebook,TAM);
            banderaAlta++;
            break;

        case 2:
            ////////////////////////////////////////////////////MODIFICAR Notebook
            if(banderaAlta > 0)
            {
                system("cls");
                modificarUnaNotebook(unaNotebook,unTipo, TAM);
                system("pasue");
            }
            else
            {
                system("cls");
                printf("Primero se debe dar de alta una notebook...\n");
                system("pause");
            }

            break;

        case 3:
            ////////////////////////////////////////////////////BORRAR Notebook
            if(banderaAlta > 0)
            {
                system("cls");
                darDeBajaUnaNotebook(unaNotebook, TAM);
                system("pasue");
            }
            else
            {
                system("cls");
                printf("Primero se debe dar de alta una notebook...\n");
                system("pause");
            }

            break;
        case 4:
            ////////////////////////////////////////////////////LISTAR NOTEBOOKS
            if(banderaAlta > 0)
            {
                system("cls");
                listarNotebooks(unaNotebook,TAM);
                printf("              MODELO     PRECIO                MARCA                 TIPO\n");
                mostrarNotebooks(unaNotebook,TAM);
                printf("\n");
                system("pause");
            }
            else
            {
                system("cls");
                printf("Primero se debe dar de alta una notebook...\n");
                system("pause");
            }

            break;
        case 5:
            ////////////////////////////////////////////////////LISTAR MARCAS
            if(banderaAlta > 0)
            {
                system("cls");
                printf("        ID                MARCA\n");
                mostrarMarcas(unaNotebook,unaMarca,TAM);
                system("pause");
            }
            else
            {
                system("cls");
                printf("Primero se debe dar de alta una notebook...\n");
                system("pause");
            }

            break;
        case 6:
            ////////////////////////////////////////////////////LISTAR TIPOS
            if(banderaAlta > 0)
            {
                system("cls");
                printf("        ID                TIPO\n");
                mostrarTipos(unaNotebook,unTipo,TAM);
                system("pause");
            }
            else
            {
                system("cls");
                printf("Primero se debe dar de alta una notebook...\n");
                system("pause");
            }

            break;
        case 7:
            ////////////////////////////////////////////////////LISTAR SERVICIOS
            system("cls");
            mostrarServicios(unServicio,TAM);
            system("pause");

            break;
        case 8:
            ////////////////////////////////////////////////////ALTA TRABAJO
            if(banderaAlta > 0)
            {
                system("cls");
                altaTrabajo(unTrabajo,unaNotebook,TAM);
                banderaAltaTrabajos = 1;
                system("pause");
            }
            else
            {
                system("cls");
                printf("Primero se debe dar de alta una notebook...\n");
                system("pause");
            }

            break;
        case 9:
            ////////////////////////////////////////////////////LISTAR TRABAJOS
            if(banderaAltaTrabajos > 0)
            {
                system("cls");
                mostrarTrabajos(unaNotebook,unTrabajo,unServicio,TAM);
                system("pause");
            }
            else
            {
                system("cls");
                printf("Primero se debe dar de alta un trabajo...\n");
                system("pause");
            }

            break;
        case 10:
            ////////////////////////////////////////////////////LISTAR NOTEBOOKS POR TIPO
            if(banderaAlta > 0)
            {
                system("cls");
                mostrarNotebooksPorTipo(unaNotebook,TAM);
                system("pause");
            }
            else
            {
                system("cls");
                printf("Primero se debe dar de alta una notebook....\n");
                system("pause");
            }

            break;
        case 11:
            ////////////////////////////////////////////////////LISTAR NOTEBOOKS POR MARCA
            if(banderaAlta > 0)
            {
                system("cls");
                mostrarNotebooksPorMarca(unaNotebook,TAM);
                system("pause");
            }
            else
            {
                system("cls");
                printf("Primero se debe dar de alta una notebook....\n");
                system("pause");
            }

            break;
        case 12:
            ////////////////////////////////////////////////////NOTEBOOK MAS BARATA
            if(banderaAlta > 0)
            {
                system("cls");
                mostrarNotebookMasBarata(unaNotebook,TAM);
                system("pause");
            }
            else
            {
                system("cls");
                printf("Primero se debe dar de alta una notebook.....\n");
                system("pause");
            }

            break;
        case 13:
            ////////////////////////////////////////////////////NOTEBOOK POR MARCA
            if(banderaAlta > 0)
            {
                system("cls");
                mostrarNotebookPorMarca(unaNotebook,TAM);
                system("pause");
            }
            else
            {
                system("cls");
                printf("Primero se debe dar de alta una notebook...\n");
                system("pause");
            }

            break;
        case 14:
            ////////////////////////////////////////////////////TIPO Y MARCA CONTADOR
            if(banderaAlta > 0)
            {
                system("cls");
                elegirTipoYMarca(unaNotebook,TAM);
                system("pause");
            }
            else
            {
                system("cls");
                printf("Primero se debe dar de alta una notebook...\n");
                system("pause");
            }

            break;
        case 15:
            ////////////////////////////////////////////////////MARCA MAS ELEGIDA
            if(banderaAlta > 0)
            {
                system("cls");
                mostrarLaMarcaMasElegida(unaNotebook,TAM);
                system("pause");
            }
            else
            {
                system("cls");
                printf("Primero se debe dar de alta una notebook...\n");
                system("pause");
            }

            break;
        case 16:
            ////////////////////////////////////////////////////SALIR
            system("cls");
            printf("Seguro que desea salir? 'S' = si: ");
            fflush(stdin);
            scanf(" %s",seguir);

            strupr(seguir);

            if (strcmp(seguir,"S") == 0)
            {
                printf("Cerrando consola...\n");
            }

            break;

        default:
            system("cls");
            printf("Esta opcion no existe...\n");
            system("pause");
            break;
        }

    }
    while (strcmp(seguir,"S") != 0);

    return 0;
}
