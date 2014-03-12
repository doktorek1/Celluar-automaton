#include <stdio.h>
#include <stdlib.h>
#include "grid.h"
void alloc_grid(int x, int y)
{
	int i;
	wskaznik pok;
	pok->tab1 = malloc( x * y * sizeof (int));
	pok->tab2 = malloc( x * y * sizeof (int));
	pok->n = x * y;
	for(i = 0; i<pok->n; i++)
		{
		pok->tab1[i] = 0;
                pok->tab2[i] = 0;
		}
}
void read_from_file_and_write_to_memory(FILE * in)
{
	int i=0, x, y, k;
	wskaznik pok;
	fscanf(in, "%d %d", &x, &y);  
	k = y;
	alloc_grid(x, y);
	while(fscanf(in, "%d %d", &x, &y) == 2)
	     {
	     pok->tab1[(x-1)*k + y - 1] = 1;	     
             }
}
