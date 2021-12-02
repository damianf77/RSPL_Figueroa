#ifndef PARSER_H_
#define PARSER_H_
#include "Libro.h"

int parserLeeLibros(FILE* pArchivo , LinkedList* pListaLibros);
int parserLeeEditoriales(FILE* pArchivo , LinkedList* pListaEditoriales);
int parserGuardarComoTexto(FILE* pArchivo , LinkedList* pArrayListMinotauroBooks,LinkedList* pListaEditoriales);
int parserGuardarComoMap(FILE* pArchivo , LinkedList* pListaLibros, LinkedList* pListaEditoriales);





#endif /* PARSER_H_ */

