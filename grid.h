#ifndef GRID_H
#define GRID_H

#include <stdio.h>
/*kjvbvb*/
typedef struct {
	int *tab1;
	int *tab2;
	int n;
} * wskaznik;

void read_from_file(FILE * in);

#endif

