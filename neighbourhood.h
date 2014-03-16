#ifndef GRID2_H
#define GRID2_H

#include <stdio.h>
#include <stdlib.h>
#include "grid.h"

typedef struct{
	int zywe;
	int martwe;
} * sasiedzi;

void give_cell_neighbours(wskaznik glowny, int *tab, sasiedzi stan, int x, int y);

#endif

