#include <stdio.h>
#include <stdlib.h>
#include "grid.h"
wskaznik alloc_grid(int x, int y)
{
	int i;
	wskaznik pok = malloc(sizeof * pok);
	pok->tab1 = malloc( x * y * sizeof *pok->tab1);
	pok->tab2 = malloc( x * y * sizeof (int));
	pok->wiersze = x;
	pok->kol = y;
	for(i = 0; i<x*y; i++)
		{
		pok->tab1[i] = 0;
                pok->tab2[i] = 0;
		}
	return pok;
}
/*void print_grid(wskaznik na_siatke, int *tab)
{
	int n = (na_siatke->wiersze)*(na_siatke->kol);
	int i,j;
	int *tmp = tab;
	for(i=0; i<na_siatke->wiersze;i++){
		for(j=0;j<na_siatke->kol;j++){
			if(*tmp == 0)
				printf(" 0 ");
			else
				printf(" %d ", *tmp);
			//printf(" %d ", *tmp);
			tmp++;}
		printf("\n");
	}
	printf("\n");
}
void print_grids(wskaznik str, int x, int y)
{
	int *tmp = str->tab1;
	int i,j;
	printf("\n\nSIATKA A:\n\n");
	for(i=0; i<x;i++){
		for(j=0;j<y;j++){
			printf(" %d ", *tmp);
			tmp++;}
		printf("\n");
		}
	printf("\n\nSIATKA B:\n\n");
	tmp = str->tab2;
	for(i=0; i<x;i++){
		for(j=0;j<y;j++){
			printf(" %d ", *tmp);
			tmp++;}
		printf("\n");
		}	
}*/
wskaznik read_from_file_and_write_to_memory(FILE * in)
{
	int i=0, x, y, k;
	wskaznik pok;
	fscanf(in, "%d %d", &x, &y);  
	k = y;
	pok = alloc_grid(x, y);
	while(fscanf(in, "%d %d", &x, &y) == 2)
	     {
	     pok->tab1[(x-1)*k + y - 1] = 1;	
             }
	//printf("Drukuje: %d %d\n", x, y);     
	//printf("Drukuje: \n");
	//printf("Drukuje: %d %d \n", pok->wiersze, pok->kol);
	//print_grids(pok, pok->wiersze, pok->kol);
	return pok;
}
void save_last_generation(wskaznik glowny, int *x, char *name)
{
	int i,j,c = 0;
	int *tmp = x;
	FILE *out = fopen(name, "w");
	fprintf(out, "%d %d\n", glowny->wiersze, glowny->kol);
	for(i=0; i < glowny->kol;i++){
		for(j=0; j < glowny->wiersze;j++){
			if(x[c] == 1)
			fprintf(out, "%d %d\n", c/(glowny->kol)+1, c%(glowny->kol)+1);
			c++;
			//fprintf(out, "%d", *tmp);
			//tmp++;
			}
		fprintf(out, "\n");
	}
	fclose(out);

}
