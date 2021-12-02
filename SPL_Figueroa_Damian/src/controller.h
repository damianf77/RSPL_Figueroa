#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "Editorial.h"
#include "FuncionesFigueroa.h"
#include "Libro.h"
#include "LinkedList.h"
#include "parser.h"

int controllerCargarDesdeTexto(char* path , LinkedList* pArrayList);
int controllerCargarEditorialesDesdeTexto(char* path, LinkedList* pArrayList);
int controllerOrdenarLibrosPorAutor(LinkedList* pArrayListBooks);
int controllerGuardarComoTexto(char* path , LinkedList* pArrayListMinotauroBooks, LinkedList* pArrayListEditorialsList);
int controllerMostrarListaLibrosEditoriales(LinkedList* booksList, LinkedList* editorialsList);
int controllerMinotauroFiltro (LinkedList* booksList, LinkedList* editorialsList);
int controllerGuardarMapeoTexto(char* path , LinkedList* pArrayListBooks, LinkedList* pArrayListEditorialsList);
int controllerLlamarMapeado(LinkedList* pArrayListBooks, LinkedList* pArrayListEditorialsList);
int controllerContar(char* path ,LinkedList* pArrayList, LinkedList* pArrayListEditorial);
int Controller_Acumulador(char* path ,LinkedList* pArrayList, LinkedList* pArrayListEditorial);




#endif /* CONTROLLER_H_ */
