#ifndef GRID_H
#define GRID_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int *tab1;
	int *tab2;
	int wiersze;
	int kol;
} * wskaznik;

void print_grid(wskaznik str, int x, int y);

wskaznik read_from_file_and_write_to_memory(FILE * in);

#endif

