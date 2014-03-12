#include <stdio.h>
#include <stdlib.h>

void alloc_grid(int x, int y)
{
	int i;
	wskaznik->tab1 = malloc( x*y*sizeof (int));
	wskaznik->tab2 = malloc( x*y*sizeof (int));
	wskaznik->n = x * y;
	for(i = 0; i<wskaznik->n; i++)
		{
		wskaznik->tab1[i] = 0;
                wskaznik->tab2[i] = 0;
		}
}
void read_from_file(FILE * in)
{
	int i=0, x, y;
	
	fscanf(in, "%d", &x); 
	fscanf(in, "%d", &y); 
	alloc_grid(x, y);
	while(fscnaf(in, "%d %d", &x, &y) == 2)
	     {
	     wskaznik->tab1[12] = x;
 	     *(wskaznik->tab2) = y;
	     wskaznik->tab1++;
	     wskaznik->tab2++;	     
             }
}
