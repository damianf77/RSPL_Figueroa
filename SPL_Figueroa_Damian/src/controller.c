#include "Controller.h"

//brief Abre un archivo que le llega por parametros y procede a parsearlo llamando a parser_BooksFromText y despues cerrarlo.
//return -1 si no se pudo abrir el archivo en cuestion o 0 si se pudo.
int controllerCargarDesdeTexto(char* path , LinkedList* pArrayList)
{
	FILE* auxFile;
	int state;

	state = -1;

	auxFile = fopen(path,"r");

	if(auxFile != NULL)
	{
		parserLeeLibros(auxFile, pArrayList);
		state = 0;

		fclose(auxFile);
	}

	return state;
}

//brief Abre un archivo que le llega por parametros y procede a parsearlo llamando a parser_EditorialsFromText y despues cerrarlo.
//return -1 si no se pudo abrir el archivo en cuestion o 0 si se pudo.
int controllerCargarEditorialesDesdeTexto(char* path, LinkedList* pArrayList)
{
	int state;
	FILE* auxFile;

	state = -1;

	auxFile = fopen(path,"r");

	if(auxFile != NULL)
	{
		parserLeeEditoriales(auxFile, pArrayList);
		state = 0;
	}

	fclose(auxFile);

	return state;
}

//brief presenta las posibilidades de ordenamiento de los vectores ya sea autores de mayor a menor o viceversa.
//return -1 si no se pudo ordenar, y 0 si se pudo ordenar satisfactoriamente.
int controllerOrdenarLibrosPorAutor(LinkedList* pArrayListBooks)
{
	int state;
	int menuOption;

	state = -1;

	if(pArrayListBooks != NULL)
	{
		menuOption = validaEntero("\n\nComo le gustaria ordenar los autores de los libros?\n\t\t "
				"1 -> (Autores [Mayor] Ascendentes) || 2 -> (Autores [Mayor]  Descendentes) \n\t\t",
				"\n\nERROR - (Ingrese una opcion correcta) - ERROR", 1, 2);

		switch (menuOption) {
			case 1:
				ll_sort(pArrayListBooks, LibroCompararPorAutor, 1);
				printf("Se han ordenado los empleados satisfactoriamente");

			break;

			default:
				ll_sort(pArrayListBooks, LibroCompararPorAutor, 0);
				printf("Se han ordenado los empleados satisfactoriamente");
			break;
		}
		state = 0;
	}

	return state;
}

//brief Abre el path en metodo de escritura se lo asigna a un puntero a File para despues poder, llama al parser y escribe lo que haya dentro de pArrayListMinotauroBooks
//return -1 si no se pudo escribir el archivo en cuestion o 0 si se pudo hacer.
int controllerGuardarComoTexto(char* path , LinkedList* pArrayListMinotauroBooks, LinkedList* pArrayListEditorialsList)
{
	int state;
	FILE* pFile;

	state = -1;

	if(path != NULL && pArrayListMinotauroBooks != NULL)
	{
		pFile = fopen(path,"w");

		if(pFile != NULL)
		{
			parserGuardarComoTexto(pFile, pArrayListMinotauroBooks,pArrayListEditorialsList);
			state = 0;
		}
			fclose(pFile);
	}

	return state;
}

//brief Muestra ambas listas con sus datos hata el momento.
//return -1 si no se pudieron mostrar, 0 si se pudieron mostrar.
int controllerMostrarListaLibrosEditoriales(LinkedList* booksList, LinkedList* editorialsList)
{
	int state;
	state = -1;

	if(booksList != NULL && editorialsList != NULL)
	{
 	   LibroMostrarLista(booksList,editorialsList);
 	   EDI_showListOfEditorials(editorialsList);
 	   state = 0;
	}

	return state;
}

//brief Llama a el filtro, le pasa la funcion criterio y devuelve la nueva LinkedList con dichos elementos, y luego llama a parser para guardarlos y copiarlos en el archivo.
//return
int controllerMinotauroFiltro (LinkedList* booksList, LinkedList* editorialsList)
{
	int state;
	LinkedList* minotaurosBookList;

	state = -1;

	if(booksList != NULL && editorialsList != NULL)
	{
	  minotaurosBookList = ll_filter(booksList,EDI_criterio);
	  if(minotaurosBookList != NULL)
	  {
		  LibroMostrarListaMinotauro(minotaurosBookList, editorialsList);
		  controllerGuardarComoTexto("LibrosEditorialMinotauro.csv", minotaurosBookList, editorialsList);
	  }
	  state = 0;
	}

	return state;
}

//brief Abre el path en metodo de escritura se lo asigna a un puntero a File para despues poder, llama al parser y escribe lo que haya dentro de pArrayListBooks
//return -1 si no se pudo escribir el archivo en cuestion o 0 si se pudo hacer.
int controllerGuardarMapeoTexto(char* path , LinkedList* pArrayListBooks, LinkedList* pArrayListEditorialsList)
{
	int state;
	FILE* pFile;

	state = -1;

	if(path != NULL && pArrayListBooks != NULL)
	{
		pFile = fopen(path,"w");

		if(pFile != NULL)
		{
			parserGuardarComoMap(pFile, pArrayListBooks,pArrayListEditorialsList);
			state = 0;
		}
			fclose(pFile);
	}

	return state;
}
/*brief
param pArrayListBooks
param pArrayListEditorialsList
return*/
int controllerLlamarMapeado(LinkedList* pArrayListBooks, LinkedList* pArrayListEditorialsList)
{
	int state;

	state = -1;

	if(pArrayListBooks != NULL && pArrayListEditorialsList != NULL)
	{
		 ll_map(pArrayListBooks, EDIBOOKPRICE_criterio);
		 controllerGuardarMapeoTexto("mapeado.csv", pArrayListBooks, pArrayListEditorialsList);
		 state = 0;
	}

	return state;
}



