/*
Author: Damian Ariel Figueroa

Parte 1

Desarrollar en ANSI C:
Un programa que realice lo siguiente:
1. Leer un archivo con los datos de libros, guardándolos en un linkedList de entidades
eLibro.
ACLARACIÓN: El nombre del archivo se debe pasar como parámetro por línea de
comandos.
2. Leer un archivo con los datos de editoriales, guardándolos en un linkedList de entidades
eEditorial.
ACLARACIÓN: El nombre del archivo se debe pasar como parámetro por línea de
comandos.
3. Ordenar la lista generada en el ítem anterior, con la función ll_sort, según el criterio de
ordenamiento “Autor” de manera ascendente.
4. Imprimir por pantalla todos los datos de los libros.
ACLARACIÓN: Se deberá imprimir la descripción de la editorial.
5. Realizar un listado de los libros de la editorial MINOTAURO. Para ello deberá utilizar la
función ll_filter* del LinkedList. Guardar el listado en un archivo csv.
Detalle de la función “ll_filter()”
Prototipo de la función:
LinkedList* ll_filter(LinkedList* this, int (*fn)(void* element))
La función “ll_filter” recibirá una lista y una función criterio “fn”. Se deberá iterar todos los elementos
de la lista y pasarlos a la función “fn”. La función “fn” devolverá 1 si ese ítem se debe agregar a la
lista resultado o 0 si no debe agregarse. La función “ll_filter” generará la nueva lista resultado,
agregará a la misma los ítems correspondientes y la devolverá.

Datos:
eLibro:
• id
• titulo
• autor
• precio
• idEditorial
eEditorial:
• idEditorial
• nombre
Las editoriales con las que trabajaremos son las siguientes. Deberán generar un archivo csv con
estos datos.
1 - PLANETA
2 - SIGLO XXI EDITORES
3 - PEARSON
4 - MINOTAURO
5 - SALAMANDRA
6 - PENGUIN BOOKS
Los datos de los libros los generarán ustedes. deberán ser los suficientes como para probar las
distintas opciones del menú.

Parte 2

Desarrollar la función ll_map en la biblioteca linkedList, la cual recibirá la lista y una función.
La función ll_map ejecutará la función recibida como parámetro por cada ítem de la lista, de
este modo se realizarán descuentos a los precios según se detalla:
* PLANETA: 20% (si el monto es mayor o igual a $300)
* SIGLO XXI EDITORES: 10% (si el monto es menor o igual a $200)
Agregar la siguiente opcion al menú de usuarios:
6. Generar el archivo de salida “mapeado.csv” luego de aplicar la función map.

Parte 3

Desarrollar la función ll_count
El prototipo sugerido es el siguiente, ero se puede modificar justificando dicha
modificación.
int ll_count(LinkedList* this, int (*fn)(void* element))
Agregar la siguiente opción al menú de usuarios:
7. Determinar cuántos libros cuestan mas de $500.
8. Determinar la sumatoria de precios de los libros de la editorial PEARSON

NOTAS:
Nota 0: El código deberá tener comentarios con la documentación de cada una de las funciones y respetar las
reglas de estilo de la cátedra.
Nota 1: Se deberá realizar el menú de opciones y las validaciones a través de funciones.
Nota 2: Se deberán utilizar las bibliotecas LinkedList, Libro y Editorial (desarrollando las funciones setter y getter
necesarias).
Nota 3: Los datos (editoriales y libros) deberán estar en listas separadas, realizando las relaciones
correspondientes entre las entidades.
Nota 4: Utilizar MVC (modelo vista controlador)
*/

#include <stdio.h>
#include <stdlib.h>
#include "controller.h"

int main(void)
{
	setbuf(stdout,NULL);
	LinkedList* booksList = ll_newLinkedList();
	LinkedList* editorialsList = ll_newLinkedList();
	int state;
	int menuOption;
	char nombredeArchivo[MAX_CHAR];


	do
       {

       	imprimeMenu();
       	menuOption = validaEntero("\n\n\t\t Por favor, ingrese una opcion del menu del 1 al 9: ",
       	"\n\n\t\t\t\t      ERROR - (Has ingresado un numero no contemplado en el menu reintente) - ERROR\n\n", 1, 7);

           switch(menuOption)
           {
           	   case 1:
           		   if(ll_isEmpty(booksList) == 1)
           		   {
           			   pedirString("\n\n\t\t\t\t\tIngrese el nombre del archivo que quiere abrir (Disponibles {Libros.csv } o :", nombredeArchivo);
           			   state = controllerCargarDesdeTexto(nombredeArchivo,booksList);

					 if(state == 0)
					 {
						 printf("\n\t\t\t\t\t\t\tSe ha cargado la lista satisfactoriamente");
					 }
					 else
					 {
						 if(state == -1)
						 {
							 printf("\n\t\t\t\t\t\t\tNo se puede cargar porque no existe!\n"
							 "\t\t\t\t\t\t\t   Intente ingresando el nombre de los disponibles nuevamente!");
						 }
						 else
						 {
							 printf("El archivo contiene datos incompatibles");
						 }

					 }
				 }
           		 else
				 {
					 printf("\n\t\t\t\t\t\t\tNo se puede cargar el archivo mas de una vez!\n"
						   "\t\t\t\t\t\t\t   Esto ocasionaria un error en el programa");
				 }
               break;
           	   case 2:
           		   if(ll_isEmpty(editorialsList) == 1)
           		   {
           			   pedirString("\n\n\t\t\t\t\tIngrese el nombre del archivo que quiere abrir (Disponibles {Editoriales.csv } o :", nombredeArchivo);
           			   state =  controllerCargarEditorialesDesdeTexto(nombredeArchivo, editorialsList);

           			   if(state == 0)
           			   {
           				   printf("\n\t\t\t\t\t\t\tSe ha cargado la lista satisfactoriamente");
           			   }
           			   else
           			   {
           				   if(state == -1)
           				   {
           					   printf("\n\t\t\t\t\t\t\tNo se puede cargar porque no existe!\n"
           							   "\t\t\t\t\t\t\t   Intente ingresando el nombre de los disponibles nuevamente!");
           				   }
           				   else
           				   {
           					   printf("El archivo contiene datos incompatibles");
           				   }

           			   }
				  }
           		  else
				  {
           			  printf("\n\t\t\t\t\t\t\tNo se puede cargar el archivo mas de una vez!\n"
						   "\t\t\t\t\t\t\t   Esto ocasionaria un error en el programa");
				  }
               break;
           	   case 3:
           		   controllerOrdenarLibrosPorAutor(booksList);
               break;
           	   case 4:
                   if(ll_isEmpty(editorialsList) == 0 && ll_isEmpty(booksList) == 0)
    			   {
                	   controllerMostrarListaLibrosEditoriales(booksList, editorialsList);
     			   }
				   else
				   {
					   printf("\n\t\t\t\t\t\t\tNo se pueden mostrar los archivos ya que no ha cargado los Libros o Editoriales!\n"
						   "\t\t\t\t\t\t\t   Esto ocasionaria un error en el programa");
				   }
               break;
           	   case 5:
           		   controllerMinotauroFiltro(booksList, editorialsList);
           	   break;
           	   case 6:
           		   controllerLlamarMapeado(booksList, editorialsList);
           	   break;
          }
       }while(menuOption != 7);



	return EXIT_SUCCESS;
}
