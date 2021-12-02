#ifndef LIBRO_H_
#define LIBRO_H_

#define MAX_CHAR 100
#include "FuncionesFigueroa.h"
#include "LinkedList.h"

struct
{
	int id;
	char titulo [MAX_CHAR];
	char autor [MAX_CHAR];
	float precio;
	int idEditorial;

}typedef eLibro;

eLibro* LibroNuevo();
eLibro* LibroCarga(char* idStr, char* titulo, char* autor, char* precio, char* editorial);
void LibroBorrar(eLibro* libros);
int LibroSetID(eLibro* libros, int id);
int LibroSetTitulo(eLibro* libros, char* titulo);
int LibroSetAutor(eLibro* libros, char* autor);
int LibroSetPrecio(eLibro* libros, float precio);
int LibroSetIdEditorial(eLibro* libros, int editorialId);
int LibroGetID(eLibro* libros, int *id);
int LibroGetTitulo(eLibro* libros, char *titulo);
int LibroGetAutor(eLibro* libros, char *autor);
int LibroGetPrecio(eLibro* libros, float *precio);
int LibroGetIdEditorial(eLibro* libros, int *editorialId);
int LibroMostrarUno(eLibro* libros, LinkedList* pListaEditoriales);
int LibroMostrarLista(LinkedList* pListaLibros, LinkedList* pListaEditoriales);
int LibroCompararPorAutor(void* elemento1, void* elemento2);
int LibroMostrarLibroMinotauro(eLibro* libros,LinkedList* pListaEditoriales);
int LibroMostrarListaMinotauro(LinkedList* pListaLibros, LinkedList* pListaEditoriales);
int librosFiltrarPearson(void* unLibro);
int libros_Contados(void* unLibro);



















#endif /* LIBRO_H_ */
