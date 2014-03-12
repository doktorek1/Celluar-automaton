#ifndef GRID_H
#define GRID_H

#include <stdio.h>

typedef struct {
	int *tab1;
	int *tab2;
	int n;
} * wskaznik;

void read_from_file_and_write_to_memory(FILE * in);

#endif

