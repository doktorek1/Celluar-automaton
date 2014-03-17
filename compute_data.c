#include <stdio.h>
#include "grid.h"
#include "neighbourhood.h"
#include "rules.h"

void operate(wskaznik glowny, int *x, int *y, sasiedzi stan)
{
	int *pom1 = x;
	int *pom2 = y;
	int i, wspl1, wspl2;//wspl1, wspl2 - odpowiednio 1 i 2 wspolrzedna
	for(i=0; i < (glowny->wiersze)*(glowny->kol);i++)
		{
		wspl1 = i/(glowny->wiersze)+1;
		wspl2 = i%(glowny->wiersze)+1;
		give_cell_neighbours( glowny, pom1, stan,  wspl1, wspl2);
		//printf("%d. %d %d\n", i + 1, stan->zywe, stan->martwe);
		if(check_if_change_cell_state(stan->zywe, stan->martwe, pom1[i]) == 1)
			pom2[i] = 1;
		else
			pom2[i] = 0;
		}

}
