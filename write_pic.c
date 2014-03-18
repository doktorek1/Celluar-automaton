#include <stdio.h>
#include <stdlib.h>
#include "grid.h"

int daj_ilosc_cyfr_w_liczbie(int x){
	int i = 10, l = 0, n;
	while( l < 100)
	{ 	
		n = x/i;
		if( n > 0 )
			l++;
		else 
			return l + 1;
		i = i * 10;
	}
	return l;
}
int potega(int n)
{
	if(n == 0) 
		return 1;
	int i, x = 10;
	for(i = 0; i < n-1; i++)
		x = x * 10;
	return x;
}
char *zamien_na_napis(int x)
{
	int i, max;//maksymalna potega 10
	int n = daj_ilosc_cyfr_w_liczbie(x);
	int *cyfry = malloc(n*sizeof (int));
	char *napis = malloc(n*sizeof (char));
	max = potega(n)/10;
	for(i = 0; i < n; i++)
		{
		cyfry[i] = x / max;//printf(" %d ", cyfry[i]);
		x = x - cyfry[i] * max;
		max=max/10;
		}
	for(i = 0; i < n; i++){
			if(cyfry[i] == 0)
				napis[i] = '0';
			if(cyfry[i] == 1)
				napis[i] = '1';
			if(cyfry[i] == 2)
				napis[i] = '2';
			if(cyfry[i] == 3)
				napis[i] = '3';
			if(cyfry[i] == 4)
				napis[i] = '4';
			if(cyfry[i] == 5)
				napis[i] = '5';
			if(cyfry[i] == 6)
				napis[i] = '6';
			if(cyfry[i] == 7)
				napis[i] = '7';
			if(cyfry[i] == 8)
				napis[i] = '8';
			if(cyfry[i] == 9)
				napis[i] = '9';//printf(" \n%c ", napis[i]);
			}
	return napis;
		
}
void save_BMP(int lp, wskaznik glowny, int *tab, char *nazwa_pliku)
{

}

