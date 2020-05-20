#include "Notebook.h"
void inicializarNotebooks(eNotebook unaNotebook[], int tam)
{
    for ( int i = 0; i < 1000; i++ )
    {
        unaNotebook[i].id = 0;
        unaNotebook[i].precio = 0;
        unaNotebook[i].idTipo = 0;
        unaNotebook[i].idMarca = 0;
        unaNotebook[i].isEmpty = VACIO;
        strcpy(unaNotebook[i].modelo, "0");
        strcpy(unaNotebook[i].marcaDescripcion.descripcion, "0");
        strcpy(unaNotebook[i].tipoDescripcion.descripcion, "0");
    }
}




void alta(eNotebook unaNotebook[], int tam)
{
    int lugar = 0;
    int entero;
    int opcion;
    char texto[50];

    //lugar = cargarIDNotebooks();
    lugar = buscarLibre(unaNotebook, tam);

    if(lugar != -1)
    {
        unaNotebook[lugar].isEmpty = LLENO;
        unaNotebook[lugar].id = lugar + 1;

        unaNotebook[lugar].idTipo = cargarIDTipos();
        unaNotebook[lugar].tipoDescripcion.id = unaNotebook[lugar].idTipo;

        unaNotebook[lugar].idMarca = cargarIDMarcas();
        unaNotebook[lugar].marcaDescripcion.id = unaNotebook[lugar].idMarca;

        do
        {
            printf("Ingrese el modelo: ");
            fflush(stdin);
            gets(texto);
        }
        while(strlen(texto) > 21);

        strcpy(unaNotebook[lugar].modelo, texto);

        do
        {
            printf("\nIngrese la marca de la notebook 1)Compaq 2)Asus 3)Acer 4)HP \nutilize los numeros mostrados arriba: ");
            scanf(" %d",&opcion);

            switch (opcion)
            {
            case 1:
                strcpy(unaNotebook[lugar].marcaDescripcion.descripcion,"Compaq");
                break;

            case 2:
                strcpy(unaNotebook[lugar].marcaDescripcion.descripcion,"Asus");
                break;

            case 3:
                strcpy(unaNotebook[lugar].marcaDescripcion.descripcion,"Acer");
                break;

            case 4:
                strcpy(unaNotebook[lugar].marcaDescripcion.descripcion,"HP");
                break;

            default:
                system("cls");
                printf("Opcion incorrecta...\n");
                system("pause");
                break;
            }
        }
        while(opcion > 4 || opcion < 1);

        do
        {
            printf("\nIngrese el tipo de notebook 1)Gamer 2)Disenio 3)Ultrabook 4)Normalita \nutilize los numeros mostrados arriba: ");
            scanf("%d",&opcion);

            switch (opcion)
            {
            case 1:
                strcpy(unaNotebook[lugar].tipoDescripcion.descripcion,"Gamer");
                break;

            case 2:
                strcpy(unaNotebook[lugar].tipoDescripcion.descripcion,"Disenio");
                break;

            case 3:
                strcpy(unaNotebook[lugar].tipoDescripcion.descripcion,"Ultrabook");
                break;

            case 4:
                strcpy(unaNotebook[lugar].tipoDescripcion.descripcion,"Normalita");
                break;

            default:
                system("cls");
                printf("Opcion incorrecta...\n");
                system("pause");
                break;
            }
        }
        while(opcion > 4 || opcion < 1);

        do
        {
            printf("\nIngrese el precio: ");
            entero = scanf(" %f", &unaNotebook[lugar].precio);
            fflush(stdin);
        }
        while(entero == 0);

    }
    else
    {
        printf("No queda mas espacio...\n");
        system("pause");
    }
}

int buscarLibre(eNotebook unaNotebook[], int tam)
{
    int indice = -1;

    for (int i = 0; i < tam; i++)
    {
        if (unaNotebook[i].isEmpty == VACIO)
        {
            indice = i;
            break;
        }
    }

    return indice;
}






int cargarIDNotebooks (void)
{
    static int idNotebook = 0;

    idNotebook++;
    return idNotebook;
}





void darDeBajaUnaNotebook(eNotebook unaNotebook[], int tam)
{
    int id;
    char confirmar;
    int encontro = 0;

    printf("Ingrese la id de la notebook a dar de baja: ");
    scanf(" %d",&id);

    for(int i = 0; i < tam; i++)
    {
        if (unaNotebook[i].id == id)
        {
            encontro = 1;
            printf("\nLa notebook que selecciono es: \n");
            printf("              MODELO     PRECIO                MARCA                 TIPO\n");
            mostrarNotebook(unaNotebook[i]);

            printf("\n\nDesea dar de baja a esa notebook? S = SI: ");
            scanf(" %c",&confirmar);

            confirmar = toupper(confirmar);

            if(confirmar == 'S')
            {
                unaNotebook[i].isEmpty = VACIO;
                system("cls");
                printf("Se dio de baja...\n");
                system("pause");
            }
            else
            {
                printf("No se dio de baja...\n");
                system("pause");
            }
            break;
        }
    }

    if(encontro != 1)
    {
        system("cls");
        printf("No se encontro una notebok con esta id...\n");
        system("pause");
    }
}









void modificarUnaNotebook(eNotebook unaNotebook[],eTipo unTipo[],int tam)
{
    int i;
    int id;
    int entero;
    int opcion;
    char seguir;
    int modificar;
    int encontro = 0;
    char verificar = 'N';

    printf("Ingrese la id de la notebook a modificar: ");
    scanf(" %d",&id);

    for(i = 0; i < tam; i++)
    {
        if(unaNotebook[i].isEmpty == LLENO && id == unaNotebook[i].id)
        {
            encontro = 1;
            printf("\nLA NOTEBOOK INGRESADA ES:\n");
            printf("              MODELO     PRECIO                MARCA                 TIPO\n");
            mostrarNotebook(unaNotebook[i]);

            printf("\n\nQuiere modificar esta notebook? 'S' = SI: ");
            scanf(" %c",&verificar);

            verificar = toupper(verificar);

            if(verificar == 'S')
            {
                do
                {
                    system("cls");
                    printf("1) Precio\n2) Tipo\nQue desea modificar ?: ");
                    scanf(" %d",&modificar);

                    switch(modificar)
                    {
                    case 1:
                        do
                        {
                            printf("Ingrese el precio: ");
                            entero = scanf(" %f", &unaNotebook[i].precio);
                            fflush(stdin);
                        }
                        while(entero == 0);
                        break;

                    case 2:
                        do
                        {
                            printf("\nIngrese el tipo de notebook 1)Gamer 2)Disenio 3)Ultrabook 4)Normalita \nutilize los numeros mostrados arriba: ");
                            scanf("%d",&opcion);

                            switch (opcion)
                            {
                            case 1:
                                strcpy(unaNotebook[i].tipoDescripcion.descripcion,"Gamer");
                                break;

                            case 2:
                                strcpy(unaNotebook[i].tipoDescripcion.descripcion,"Disenio");
                                break;

                            case 3:
                                strcpy(unaNotebook[i].tipoDescripcion.descripcion,"Ultrabook");
                                break;

                            case 4:
                                strcpy(unaNotebook[i].tipoDescripcion.descripcion,"Normalita");
                                break;

                            default:
                                system("cls");
                                printf("Opcion incorrecta...\n");
                                system("pause");
                                break;
                            }
                        }
                        while(opcion > 4 || opcion < 1);
                        break;

                    default:
                        system("cls");
                        printf("Esta opcion no existe...\n");
                        system("pause");
                        break;
                    }

                    system("cls");
                    printf("Desea seguir modificando a la notebook? 'S' = SI: ");
                    scanf(" %c",&seguir);

                    seguir = toupper(seguir);

                }
                while(seguir == 'S');
            }
        }
    }

    if(encontro == 0)
    {
        system("cls");
        printf("No se encontro una notebook con esta id...\n");
        system("pause");
    }
}





void listarNotebooks(eNotebook unaNotebook[], int tam)
{
    eNotebook auxNotebook;

    for(int i = 0; i < tam - 1; i++)
    {
        if(unaNotebook[i].isEmpty == LLENO)
        {
            for(int j = i + 1; j < tam; j++)
            {
                if(unaNotebook[j].isEmpty == LLENO)
                {
                    if(strcmp(unaNotebook[i].modelo, unaNotebook[i].modelo) > 0)
                    {
                        auxNotebook = unaNotebook[i];
                        unaNotebook[i] = unaNotebook[j];
                        unaNotebook[j] = auxNotebook;
                    }
                    else if (strcmp(unaNotebook[i].modelo, unaNotebook[i].modelo) == 0 && unaNotebook[i].precio > unaNotebook[j].precio)
                    {
                        auxNotebook = unaNotebook[i];
                        unaNotebook[i] = unaNotebook[j];
                        unaNotebook[j] = auxNotebook;
                    }
                }
            }
        }
    }
}



void mostrarNotebook(eNotebook unaNotebook)
{
    printf("%20s %10.2f %20s %20s\n",unaNotebook.modelo,unaNotebook.precio, unaNotebook.marcaDescripcion.descripcion, unaNotebook.tipoDescripcion.descripcion);
}

void mostrarNotebookConID(eNotebook unaNotebook)
{
    printf("%5d %20s %10.2f %20s %20s\n",unaNotebook.id,unaNotebook.modelo,unaNotebook.precio, unaNotebook.marcaDescripcion.descripcion, unaNotebook.tipoDescripcion.descripcion);
}


void mostrarNotebooks(eNotebook unaNotebook[], int tam)
{
    int vandera = VACIO;

    for (int i = 0; i < tam; i++)
    {
        if(unaNotebook[i].isEmpty == LLENO)
        {
            mostrarNotebook(unaNotebook[i]);
            vandera = LLENO;
        }
    }

    if(vandera == VACIO)
    {
        printf("No hay notebooks que listar...\n\n");
    }
}

void mostrarNotebooksPorTipo(eNotebook unaNotebook[], int tam)
{
    int opcion;
    char tipoSeleccionado[21];
    int mostrarError = 0;

    do
        {
            system("cls");
            printf("\nIngrese el tipo de notebook que quiere mostrar\n1)Gamer\n2)Disenio\n3)Ultrabook\n4)Normalita\nutilize los numeros mostrados arriba: ");
            scanf("%d",&opcion);

            switch (opcion)
            {
            case 1:
                strcpy(tipoSeleccionado,"Gamer");
                break;

            case 2:
                strcpy(tipoSeleccionado,"Disenio");
                break;

            case 3:
                strcpy(tipoSeleccionado,"Ultrabook");
                break;

            case 4:
                strcpy(tipoSeleccionado,"Normalita");
                break;

            default:
                system("cls");
                printf("Opcion incorrecta...\n");
                system("pause");
                break;
            }
        }
        while(opcion > 4 || opcion < 1);

        system("cls");
        printf("              MODELO     PRECIO                MARCA                 TIPO\n");

        for(int i = 0; i < tam; i++)
        {
            if(strcmp(unaNotebook[i].tipoDescripcion.descripcion,tipoSeleccionado) == 0)
            {
                mostrarError = 1;
                mostrarNotebook(unaNotebook[i]);
            }
        }

         if(mostrarError == 0)
        {
            printf("\nNo se encontro ninguna notebook con esa marca...\n\n");
        }
}










void mostrarNotebooksPorMarca(eNotebook unaNotebook[], int tam)
{
    int opcion;
    char marcaSeleccionada[21];
    int mostrarError = 0;

    do
        {
            system("cls");
            printf("\nIngrese la marca de notebook que quiere mostrar\n1)Compaq\n2)Asus\n3)Acer\n4)HP\nutilize los numeros mostrados arriba: ");
            scanf("%d",&opcion);

            switch (opcion)
            {
            case 1:
                strcpy(marcaSeleccionada,"Compaq");
                break;

            case 2:
                strcpy(marcaSeleccionada,"Asus");
                break;

            case 3:
                strcpy(marcaSeleccionada,"Acer");
                break;

            case 4:
                strcpy(marcaSeleccionada,"HP");
                break;

            default:
                system("cls");
                printf("Opcion incorrecta...\n");
                system("pause");
                break;
            }
        }
        while(opcion > 4 || opcion < 1);

        system("cls");
        printf("              MODELO     PRECIO                MARCA                 TIPO\n");

        for(int i = 0; i < tam; i++)
        {
            if(strcmp(unaNotebook[i].marcaDescripcion.descripcion,marcaSeleccionada) == 0)
            {
                mostrarError = 1;
                mostrarNotebook(unaNotebook[i]);
            }
        }

        if(mostrarError == 0)
        {
            printf("\nNo se encontro ninguna notebook con esa marca...\n\n");
        }
}

void mostrarNotebookMasBarata(eNotebook unaNotebook[], int tam)
{
    float minimo = 0;
    int vandera = 0;

    for(int i = 0; i < tam; i++)
    {
        if(vandera == 0)
        {
            minimo = unaNotebook[i].precio;
        }
            if(unaNotebook[i].isEmpty == LLENO && unaNotebook[i].precio < minimo)
            {
                minimo = unaNotebook[i].precio;
            }

        vandera++;
    }

    printf("La / las notebooks con menor precio son: \n");
    printf("              MODELO     PRECIO                MARCA                 TIPO\n");

     for(int i = 0; i < tam; i++)
    {
        if(unaNotebook[i].precio == minimo)
        {
            mostrarNotebook(unaNotebook[i]);
        }
    }

}










void mostrarNotebookPorMarca(eNotebook unaNotebook[], int tam)
{
    int validar = 0;



    printf("---Compaq---\n");
    for(int i = 0; i < tam; i++)
    {
        if(unaNotebook[i].isEmpty == LLENO && strcmp(unaNotebook[i].marcaDescripcion.descripcion,"Compaq") == 0)
        {
            if(validar == 0)
            {
                printf("              MODELO     PRECIO                MARCA                 TIPO\n");
            }
            validar = 1;
            mostrarNotebook(unaNotebook[i]);
        }
    }

    if(validar == 0)
    {
        printf("\nNo hay notebooks de esta marca...\n");
    }else{validar = 0;};


    printf("\n---Asus---\n");
    for(int i = 0; i < tam; i++)
    {
        if(unaNotebook[i].isEmpty == LLENO && strcmp(unaNotebook[i].marcaDescripcion.descripcion,"Asus") == 0)
        {
            if(validar == 0)
            {
                printf("              MODELO     PRECIO                MARCA                 TIPO\n");
            }
            validar = 1;
            mostrarNotebook(unaNotebook[i]);
        }
    }

    if(validar == 0)
    {
        printf("\nNo hay notebooks de esta marca...\n");
    }else{validar = 0;};



    printf("\n---Acer---\n");
    for(int i = 0; i < tam; i++)
    {
        if(unaNotebook[i].isEmpty == LLENO && strcmp(unaNotebook[i].marcaDescripcion.descripcion,"Acer") == 0)
        {
            if(validar == 0)
            {
                printf("              MODELO     PRECIO                MARCA                 TIPO\n");
            }
            validar = 1;
            mostrarNotebook(unaNotebook[i]);
        }
    }

    if(validar == 0)
    {
        printf("\nNo hay notebooks de esta marca...\n");
    }else{validar = 0;};




    printf("\n---HP---\n");
    for(int i = 0; i < tam; i++)
    {
        if(unaNotebook[i].isEmpty == LLENO && strcmp(unaNotebook[i].marcaDescripcion.descripcion,"HP") == 0)
        {
            if(validar == 0)
            {
                printf("              MODELO     PRECIO                MARCA                 TIPO\n");
            }
            validar = 1;
            mostrarNotebook(unaNotebook[i]);
        }
    }

    if(validar == 0)
    {
        printf("\nNo hay notebooks de esta marca...\n\n");
    }else{validar = 0;};
}










void elegirTipoYMarca(eNotebook unaNotebook[], int tam)
{
    int opcion;
    char tipoSeleccionado[21];
    char marcaSeleccionada[21];
    int contador = 0;

    do
        {
            system("cls");
            printf("\nIngrese el tipo de notebook que quiere mostrar\n1)Gamer\n2)Disenio\n3)Ultrabook\n4)Normalita\nutilize los numeros mostrados arriba: ");
            scanf("%d",&opcion);

            switch (opcion)
            {
            case 1:
                strcpy(tipoSeleccionado,"Gamer");
                break;

            case 2:
                strcpy(tipoSeleccionado,"Disenio");
                break;

            case 3:
                strcpy(tipoSeleccionado,"Ultrabook");
                break;

            case 4:
                strcpy(tipoSeleccionado,"Normalita");
                break;

            default:
                system("cls");
                printf("Opcion incorrecta...\n");
                system("pause");
                break;
            }
        }
        while(opcion > 4 || opcion < 1);

    do
        {
            system("cls");
            printf("\nIngrese la marca de notebook que quiere mostrar\n1)Compaq\n2)Asus\n3)Acer\n4)HP\nutilize los numeros mostrados arriba: ");
            scanf("%d",&opcion);

            switch (opcion)
            {
            case 1:
                strcpy(marcaSeleccionada,"Compaq");
                break;

            case 2:
                strcpy(marcaSeleccionada,"Asus");
                break;

            case 3:
                strcpy(marcaSeleccionada,"Acer");
                break;

            case 4:
                strcpy(marcaSeleccionada,"HP");
                break;

            default:
                system("cls");
                printf("Opcion incorrecta...\n");
                system("pause");
                break;
            }
        }
        while(opcion > 4 || opcion < 1);


    for(int i = 0; i < tam; i++)
    {
        if(strcmp(unaNotebook[i].tipoDescripcion.descripcion,tipoSeleccionado) == 0 && strcmp(unaNotebook[i].marcaDescripcion.descripcion,marcaSeleccionada) == 0)
        {
            contador++;
        }
    }

    printf("\n\nLa cantidad de notebooks con el tipo y marca especificado es de: %d\n\n",contador);
}

void mostrarLaMarcaMasElegida(eNotebook unaNotebook[], int tam)
{
    int maximoUno = 0;
    int maximoDos= 0;
    int maximo = 0;
    int Compaq = 0;
    int Asus = 0;
    int Acer = 0;
    int HP = 0;

    for(int i = 0; i < tam; i++)
    {
        if(strcmp(unaNotebook[i].marcaDescripcion.descripcion,"Compaq") == 0)
        {
            Compaq++;
        }else if(strcmp(unaNotebook[i].marcaDescripcion.descripcion,"Asus") == 0)
        {
            Asus++;
        }else if(strcmp(unaNotebook[i].marcaDescripcion.descripcion,"Acer") == 0)
        {
            Acer++;
        }else if(strcmp(unaNotebook[i].marcaDescripcion.descripcion,"HP") == 0)
        {
            HP++;
        }
    }

    if(Compaq > Asus)
    {
        maximoUno = Compaq;
    }else
    {
        maximoUno = Asus;
    };


    if(Acer > HP)
    {
        maximoDos = Acer;
    }else
    {
        maximoDos = HP;
    };


    if(maximoUno > maximoDos)
    {
        maximo = maximoUno;
    }else
    {
        maximo = maximoDos;
    };

    if(Compaq == maximo)
    {
        printf("La marca mas seleccionada es Compaq...\n\n");
    }
    if(Asus == maximo)
    {
        printf("La marca mas seleccionada es Asus...\n\n");
    }
    if(Acer == maximo)
    {
        printf("La marca mas seleccionada es Acer...\n\n");
    }if(HP == maximo)
    {
        printf("La marca mas seleccionada es HP...\n\n");
    }
}
