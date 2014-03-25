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

void print_grids(wskaznik str, int x, int y);

void print_grid(wskaznik na_siatke, int *x);

wskaznik read_from_file_and_write_to_memory(FILE * in);

void save_last_generation(wskaznik glowny, int *x, char *name);

#endif

