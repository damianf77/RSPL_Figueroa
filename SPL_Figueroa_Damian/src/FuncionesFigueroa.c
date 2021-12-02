#include "FuncionesFigueroa.h"

void imprimeMenu(void)
{

	printf("\t\t		BIENVENIDO AL MENU DE OPCIONES\n");
	printf("\t\t 1) Leer un archivo con los datos de libros, guardándolos en un linkedList de entidades eLibro.\n");
	printf("\t\t 2) Leer un archivo con los datos de editoriales, guardándolos en un linkedList de entidades eEditorial.\n");
	printf("\t\t 3) Ordenar la lista generada en el ítem anterior, con la función ll_sort, según el criterio de ordenamiento “Autor” de manera ascendente.\n");
	printf("\t\t 4) Imprimir por pantalla todos los datos de los libros.\n");
	printf("\t\t 5) Realizar un listado de los libros de la editorial MINOTAURO. Para ello deberá utilizar la función ll_filter* del LinkedList.\n");
	printf("\t\t 6) Generar el archivo de salida “mapeado.csv” luego de aplicar la función map.\n");
	printf("\t\t 7) Determinar cuántos libros cuestan mas de $500.\n");
	printf("\t\t 8) Determinar la sumatoria de precios de los libros de la editorial PEARSON\n");
	printf("\t\t 9) Salir\n");
}

int validaEntero(char mensaje [], char error [], int min, int max)
{
	char integrer[MAX];
	int validIntegrer;

	validIntegrer = validacionSoloEnteros(integrer,error,mensaje, min, max);

	return validIntegrer;

}

int validacionSoloEnteros(char integrer [],char error [], char mensaje[], int min, int max)
{
	int resultado = 0;
	int valido;
	do
	{
		valido = 1;
		printf ("%s",mensaje);
		scanf ("%s", integrer);

	/*	for(char* ptr = integrer; *ptr != 0; ptr++)
		{
			if (!isdigit(*ptr))
			{

			}
		}
*/
		while(valido == 0)
		{
			char *ptr;

			ptr = integrer;

			if(!isdigit(*ptr))
			printf("\n\n\t\t\t\t\t    ERROR - (Has ingresado %s y solo se aceptan numeros) - ERROR\n", integrer);
			valido = 0;
		}


		if (valido == 1)
		{
			resultado = atof(integrer);
			if (resultado < min || resultado > max)
			{
				valido = 0;
			}

			if(valido == 0)
			{
				printf("%s", error);
			}
		}
	} while (!valido);

	return resultado;
}

int pedirString(char mensaje[],char str[])
{
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%[^\n]s", str);

    return 1;
}

int validacionSoloChar(char str[])
{
   int i=0;

   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}

int pedirDireccion (char message[], char str[])
{
    printf("%s",message);
    fflush(stdin);
    scanf("%[^\n]s",str);

    return 1;
}

int verificaPedirString(char mensaje[], char mensajeError[], char *input)
{
    int retorno = -1;
    char aux[256];

    pedirString(mensaje, aux);

    while (retorno == -1)
    {
        if (validacionSoloChar(aux) == 0)
        {
            pedirString(mensajeError, aux);
        }
        else
        {
            retorno = 0;
            strcpy(input, aux);
        }
    }
    return retorno;
}
