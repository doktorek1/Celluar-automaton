#include <stdio.h>
#include "grid.h"
#include "neighbourhood.h"
#include "rules.h"

void operate(wskaznik glowny, int *x, int *y, sasiedzi stan)
{
	int *pom1 = x;
	int *pom2 = y;
	int i, wspl1, wspl2;
	for(i=0; i < (glowny->wiersze)*(glowny->kol);i++)
		{
		wspl1 = i/(glowny->kol)+1;
		wspl2 = i%(glowny->kol)+1;
		
		give_cell_neighbours( glowny, pom1, stan,  wspl1, wspl2);
		
		if(check_if_change_cell_state(stan->zywe, stan->martwe, pom1[i]) == 1)
			pom2[i] = 1;
		else
			pom2[i] = 0;
		}

}
