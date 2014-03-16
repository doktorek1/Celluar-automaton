#include <stdio.h>
#include <stdlib.h>
#include "grid.h"
#include "neighbourhood.h"
//(x-1)*k + y - 1
void give_cell_neighbours(wskaznik glowny, int *tab, sasiedzi stan, int x, int y)
{	
	int liczba_zywych = 0, liczba_martwych = 0;
	if(tab[(x-2)*(glowny->kol) + y - 2] == 1)
		liczba_zywych++; else liczba_martwych++;
	if(tab[(x-2)*(glowny->kol) + y - 1] == 1)
		liczba_zywych++; else liczba_martwych++;
	if(tab[(x-2)*(glowny->kol) + y] == 1)
		liczba_zywych++; else liczba_martwych++;
	if(tab[(x-1)*(glowny->kol) + y - 2] == 1)
		liczba_zywych++; else liczba_martwych++;
	if(tab[(x-1)*(glowny->kol) + y] == 1)
		liczba_zywych++; else liczba_martwych++;
	if(tab[(x)*(glowny->kol) + y - 2] == 1)
		liczba_zywych++; else liczba_martwych++;
	if(tab[(x)*(glowny->kol) + y - 1] == 1)
		liczba_zywych++; else liczba_martwych++;
	if(tab[(x)*(glowny->kol) + y] == 1)
		liczba_zywych++; else liczba_martwych++;

	stan->zywe =  liczba_zywych;
	stan->zywe =  liczba_martwych;
}
