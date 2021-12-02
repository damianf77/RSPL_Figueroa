#ifndef FUNCIONESFIGUEROA_H_
#define FUNCIONESFIGUEROA_H_

#define MAX 100

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void imprimeMenu(void);
int validaEntero(char mensaje [], char error [], int min, int max);
int validacionSoloEnteros(char integrer[], char mensaje[],char error [], int min, int max);
int pedirString(char mensaje[],char str[]);
int validacionSoloChar(char str[]);
int pedirDireccion (char message [], char str[]);
int verificaPedirString(char mensaje[], char mensajeError[], char *input);

#endif /* FUNCIONESFIGUEROA_H_ */
