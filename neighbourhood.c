#include <stdio.h>
#include <stdlib.h>
#include "grid.h"
#include "neighbourhood.h"
//(x-1)*k + y - 1
void give_cell_neighbours(wskaznik glowny, int *tab, sasiedzi stan, int x, int y)
{	
	int liczba_zywych = 0, liczba_martwych = 0, a, b, k, w;
	w = glowny->wiersze;
	k = glowny->kol;
	//1	
	a = x - 1; b = y - 1;
	if(a>0 && b>0 && tab[(a-1)*k +b-1]==1)
		liczba_zywych++;
	else if(a>0 && b > 0)
		liczba_martwych++;
	//2
	a = x - 1; b = y;

	if(a > 0 && tab[(a-1)*k +b-1] == 1)
		liczba_zywych++;
	else if(a > 0)
		liczba_martwych++;
	//3
	a = x - 1; b = y + 1;
	
	if(a > 0 && b <= k && tab[(a-1)*k +b-1]==1)
		liczba_zywych++;
	else if(a > 0 && b <= k)
		liczba_martwych++;
	//4
	a = x; b = y - 1;
	
	if(b > 0 && tab[(a-1)*k +b-1]==1)
		liczba_zywych++;
	else if( b > 0)
		liczba_martwych++;
	//5	
	a = x ; b = y + 1;
	
	if( b <= k && tab[(a-1)*k +b-1]==1)
		liczba_zywych++;
	else if(b <= k)
		liczba_martwych++;
	a = x + 1; b = y - 1;
	//6
	if( a <= w && b >0 && tab[(a-1)*k +b-1]==1)
		liczba_zywych++;
	else if(a <= w && b > 0)
		liczba_martwych++;
	//7
	a = x +1 ; b = y ;
	
	if(a <= w && tab[(a-1)*k +b-1]==1)
		liczba_zywych++;
	else if(a <= w)
		liczba_martwych++;
	//8
	a = x + 1; b = y + 1;
	if( a <= w && b <= k && tab[(a-1)*k +b-1]==1)
		liczba_zywych++;
	else if(a <= w && b <= k)
		liczba_martwych++;

	stan->zywe =  liczba_zywych;
	stan->martwe =  liczba_martwych;

}


/*if(x==1 && y==1){
	int i,j,*tmp = tab;
	for(i=0; i<glowny->kol;i++){
		for(j=0; j<glowny->wiersze;j++){
			printf(" %d ", *tmp);
			tmp++;}
		printf("\n");
		}
	
	}*/

/*if(tab[(x-2)*(glowny->kol) + y - 2] == 1 && x-1>0 && y-1 >0 )
		liczba_zywych++; else liczba_martwych++;
	if(tab[(x-2)*(glowny->kol) + y - 1] == 1 && x-1 >0 )
		liczba_zywych++; else liczba_martwych++;
	if(tab[(x-2)*(glowny->kol) + y] == 1 && x-1 >0 && y<glowny->kol)
		liczba_zywych++; else liczba_martwych++;
	if(tab[(x-1)*(glowny->kol) + y - 2] == 1 && x-1>0)
		liczba_zywych++; else liczba_martwych++;
	if(tab[(x-1)*(glowny->kol) + y] == 1 && y < glowny->kol)
		liczba_zywych++; else liczba_martwych++;
	if(tab[(x)*(glowny->kol) + y - 2] == 1 && y-1>0 && x < glowny->wiersze)
		liczba_zywych++; else liczba_martwych++;
	if(tab[(x)*(glowny->kol) + y - 1] == 1 && x < glowny->wiersze)
		liczba_zywych++; else liczba_martwych++;
	if(tab[(x)*(glowny->kol) + y] == 1 && x < glowny->wiersze && y < glowny->kol)
		liczba_zywych++; else liczba_martwych++;*/
