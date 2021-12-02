#include "Libro.h"

#include "Controller.h"

//brief Crea espacio en memoria dinamica para el nuevo libro.
//return El espacio de memoria asignado para poder empezar a trabajar.
eLibro* LibroNuevo()
{
	eLibro* newBook;

	newBook = (eLibro*) calloc(1,sizeof(eLibro)); // Consigue espacio mediante memoria dinamica para la estructura empleado

	return newBook;
}

//brief Recibe todos los datos en tipo string que contiene el archivo para meterlos dentro de la LinkedList.
//return un puntero a book ya cargado para usarlo o agregarlo a la LinkedList.
eLibro* LibroCarga(char* idStr, char* titleStr, char* authorStr, char* priceStr, char* editorialStr)
{
	eLibro* newBook;

	newBook = LibroNuevo();

	int id;
	char title[MAX_CHAR];
	char author[MAX_CHAR];
	float price;
	int editorialId;

	id = atoi(idStr);
	strcpy(title,titleStr);
	strcpy(author,authorStr);
	price = atoi(priceStr);
	editorialId = atoi(editorialStr);

	LibroSetID(newBook, id);
	LibroSetTitulo(newBook, title);
	LibroSetAutor(newBook, author);
	LibroSetPrecio(newBook, price);
	LibroSetIdEditorial(newBook,editorialId);

	return newBook;
}

//brief Libera el espacio de memoria del dato pasado por parametros.
void LibroBorrar(eLibro* this)
{
	free(this);
}

//brief Toma el dato que le llega por parametros y se lo asigna a this.
//return -1 si se no pudo hacer correctamente, 0 si pudo asignarse correctamente.
int LibroSetID(eLibro* this, int id)
{
	int state;

	state = -1;

	if(this != NULL && id > 0)
	{
		this->id = id;
		state = 0;
	}

	return state;
}

//brief Toma el dato que le llega por parametros y se lo asigna a this.
//return -1 si se no pudo hacer correctamente, 0 si pudo asignarse correctamente.
int LibroSetTitulo(eLibro* this, char* title)
{
	int state;

	state = -1;

	if(this != NULL && title != NULL)
	{
		strcpy(this->titulo, title);
		state = 0;
	}

	return state;
}

//brief Toma el dato que le llega por parametros y se lo asigna a this.
//return -1 si se no pudo hacer correctamente, 0 si pudo asignarse correctamente.
int LibroSetAutor(eLibro* this, char* author)
{
	int state;

	state = -1;

	if(this != NULL && author != NULL)
	{
		strcpy(this->autor, author);
		state = 0;
	}

	return state;
}

//brief Toma el dato que le llega por parametros y se lo asigna a this.
//return -1 si se no pudo hacer correctamente, 0 si pudo asignarse correctamente.
int LibroSetPrecio(eLibro* this, float price)
{
	int state;

	state = -1;

	if(this != NULL)
	{
		this->precio = price;
		state = 0;
	}

	return state;
}

//brief Toma el dato que le llega por parametros y se lo asigna a this.
//return -1 si se no pudo hacer correctamente, 0 si pudo asignarse correctamente.
int LibroSetIdEditorial(eLibro* this, int editorialId)
{
	int state;

	state = -1;

	if(this != NULL && editorialId > 0)
	{
		this->idEditorial = editorialId;
		state = 0;
	}

	return state;
}

//brief Guarda lo que tenga el this dentro del tipo de dato, pasado por parametros.
//return -1 si se no pudo hacer correctamente, 0 si pudo asignarse correctamente.
int LibroGetID(eLibro* this, int *id)
{
	int state;

	state = -1;

	if(this != NULL && id != NULL)
	{
		*id = this-> id;
	}

	return state;
}

//brief Guarda lo que tenga el this dentro del tipo de dato, pasado por parametros.
//return -1 si se no pudo hacer correctamente, 0 si pudo asignarse correctamente.
int LibroGetTitulo(eLibro* this, char *title)
{
	int state;

	state = -1;

	if(this != NULL && title != NULL)
	{
		strcpy(title, this->titulo);
		state = 0;
	}

	return state;
}

//brief Guarda lo que tenga el this dentro del tipo de dato, pasado por parametros.
//return -1 si se no pudo hacer correctamente, 0 si pudo asignarse correctamente.
int LibroGetAutor(eLibro* this, char *author)
{
	int state;

	state = -1;

	if(this != NULL && author != NULL)
	{
		strcpy(author, this->autor);
	}

	return state;
}

//brief Guarda lo que tenga el this dentro del tipo de dato, pasado por parametros.
//return -1 si se no pudo hacer correctamente, 0 si pudo asignarse correctamente.
int LibroGetPrecio(eLibro* this, float *price)
{
	int state;

	state = -1;

	if(this != NULL && price != NULL)
	{
		*price = this->precio;
	}

	return state;
}

//brief Guarda lo que tenga el this dentro del tipo de dato, pasado por parametros.
//return -1 si se no pudo hacer correctamente, 0 si pudo asignarse correctamente.
int LibroGetIdEditorial(eLibro* this, int *editorialId)
{
	int state;

	state = -1;

	if(this != NULL && editorialId != NULL)
	{
		*editorialId = this->idEditorial;
	}

	return state;
}

//brief Obtiene cada uno de los campos de this mediante los geters en esa posición para poder printearlos.
//return -1 si se no pudo hacer correctamente, 0 si pudo correctamente.
int LibroMostrarUno(eLibro* this, LinkedList* pArrayListEditorials)
{
	int state;
	int id;
	char title [MAX_CHAR];
	char author [MAX_CHAR];
	float price;
	int editorialId;
	char editorial[MAX_CHAR];
	Editorial* editorialName;

	state = -1;

	if(this != NULL)
	{
		LibroGetID(this, &id);
		LibroGetTitulo(this, title);
		LibroGetAutor(this, author);
		LibroGetPrecio(this, &price);
		LibroGetIdEditorial(this, &editorialId);
		editorialName = bringEditorials(pArrayListEditorials, editorialId);
		EDI_getEditorialName(editorialName, editorial);

		printf("\t\t\t|%4d  |%30s   | %22s         |   %9.2f  |    %18s   |\n",id,title,author,price,editorial);
		state = 0;
	}

	return state;
}

//brief Recorre la cantidad de elementos que hayan sido cargados en pArrayListBooks y llama a showOneBook para printear cada uno.
//return -1 si se no pudo hacer correctamente, 0 si pudo correctamente.
int LibroMostrarLista(LinkedList* pArrayListBooks, LinkedList* pArrayListEditorials)
{
	eLibro* aux;
	int state;
	int booksQty;

	state = -1;

	if(pArrayListBooks != NULL)
	{
		booksQty = ll_len(pArrayListBooks);

		printf("\n\n\t\t\t|  ID  |              Title              |             Author             |    Price     |         Editorial       |\n");
		printf("\t\t\t|______|_________________________________|________________________________|______________|_________________________|\n");

		for(int i = 0; i < booksQty; i++)
		{
			aux = ll_get(pArrayListBooks, i);

			LibroMostrarUno(aux,pArrayListEditorials);
		}
		state = 0;
	}

	return state;
}

//brief Criterio de ordenamiento para los autores segun lo que devuelva el strcmpi.
//return El criterio que debe ser llevado a cabo 0, 1.
int LibroCompararPorAutor(void* element1, void* element2)
{
	eLibro* bookOne;
	eLibro* bookTwo;
	int criterio;
	char author1[MAX_CHAR];
	char author2[MAX_CHAR];

	if(element1 != NULL && element2 != NULL)
	{
		bookOne = (eLibro*) element1;
		bookTwo = (eLibro*) element2;

		LibroGetAutor(bookOne, author1);

		LibroGetAutor(bookTwo, author2);

		criterio = strcmpi(author1,author2);
	}

	return criterio;
}

//brief Obtiene cada uno de los campos de this mediante los geters en esa posición para poder printearlos.
//return -1 si se no pudo hacer correctamente, 0 si pudo correctamente.
int LibroMostrarLibroMinotauro(eLibro* this,LinkedList* pArrayListEditorials)
{
	Editorial* editorialName;
	int id;
	char title [MAX_CHAR];
	char author [MAX_CHAR];
	float price;
	int editorialId;
	char editorial[MAX_CHAR];
	int state;

	state = -1;

	LibroGetID(this, &id);
	LibroGetTitulo(this, title);
	LibroGetAutor(this, author);
	LibroGetPrecio(this, &price);
	LibroGetIdEditorial(this, &editorialId);
	editorialName = bringEditorials(pArrayListEditorials, editorialId);
	EDI_getEditorialName(editorialName, editorial);

	printf("\t\t\t|%4d  |%30s   | %22s         |   %9.2f  |    %18s   |\n",id,title,author,price,editorial);

	state = -1;

	return state;
}

//brief Recorre la cantidad de elementos que hayan sido cargados en pArrayListBooks y llama a showOneMinotauroBook para printear cada uno.
//return -1 si se no pudo hacer correctamente, 0 si pudo correctamente.
int LibroMostrarListaMinotauro(LinkedList* minotaurosBooks, LinkedList* pArrayListEditorials)
{
	eLibro* aux;
	int state;
	int booksQty;

	state = -1;

	if(minotaurosBooks != NULL)
	{
		booksQty = ll_len(minotaurosBooks);

		printf("\n\n\t\t\t|  ID  |              Title              |             Author             |    Price     |         Editorial       |\n");
		printf("\t\t\t|______|_________________________________|________________________________|______________|_________________________|\n");

		for(int i = 0; i < booksQty; i++)
		{
			aux = ll_get(minotaurosBooks, i);

			LibroMostrarLibroMinotauro(aux,pArrayListEditorials);
		}
		state = 0;
	}

	return state;
}

int libros_Contados(void* unLibro){
	int isOk;
	eLibro* auxiliarLibro;
	float precio;

	isOk = 0;

	if(unLibro != NULL)
	{
		auxiliarLibro = (eLibro*)unLibro;

		if(!LibroGetPrecio(auxiliarLibro, &precio))
		{
			if(precio > 500)
			{
				isOk = 1;
				puts("libro +");

			}
		}
	}

	return isOk;
}


int librosFiltrarPearson(void* unLibro)
{
	int isOk;
	eLibro* auxiliarLibro;
	int idEditorial;
	float precioLibro;
	int acumulador=0;

	isOk = 0;

	if(unLibro != NULL)
	{
		auxiliarLibro = (eLibro*)unLibro;

		if(!LibroGetIdEditorial(auxiliarLibro, &idEditorial))
		{
			if(idEditorial == 3 && !LibroGetPrecio(auxiliarLibro, &precioLibro))
			{
				acumulador += precioLibro;
				puts("Acumule un libro pearson");
				isOk = 1;
			}
		}

		printf("el acumulador es : %f", acumulador);
	}



	return isOk;
}

