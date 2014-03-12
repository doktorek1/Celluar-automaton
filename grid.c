#include <stdio.h>
#include <stdlib.h>

void alloc_grid(int x, int y)
{
	int i;
	wskaznik->tab1 = malloc( x * y * sizeof (int));
	wskaznik->tab2 = malloc( x * y * sizeof (int));
	wskaznik->n = x * y;
	for(i = 0; i<wskaznik->n; i++)
		{
		wskaznik->tab1[i] = 0;
                wskaznik->tab2[i] = 0;
		}
}
void read_from_file_and_write_to_memory(FILE * in)
{
	int i=0, x, y, k;
	fscanf(in, "%d %d", &x, &y);  
	k = y;
	alloc_grid(x, y);
	while(fscnaf(in, "%d %d", &x, &y) == 2)
	     {
	     wskaznik->tab1[(x-1)*k + y - 1] = 1;	     
             }
}
