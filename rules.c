#include <stdio.h>
#include <stdlib.h>

int check_if_change_cell_state(int n1, int n2, int czy_zywa)
{
	if(czy_zywa == 0 && n1 == 3)
		return 1;
	if(czy_zywa == 1 && (n1 == 2 || n1 == 3))
		return 1;
	else
		return 0;
}

