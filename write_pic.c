#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <png.h>
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
				napis[i] = '9';
			}
	return napis;
		
}
void save_BMP(int lp, wskaznik glowny, int *map, char *nazwa_pliku)
{
	char pom[50];
	//int *buffer = tab; 
	char *filename;
	char *numer_w_nazwie = zamien_na_napis( lp );
	strcpy(pom, nazwa_pliku);
	strcat(pom, numer_w_nazwie);
	
	filename  = pom;
	int width = glowny->kol, height = glowny->wiersze;
	int x, y;
	FILE * fp;
	png_structp png_ptr;
	png_infop info_ptr;
	png_bytep row;

	fp = fopen( filename, "wb" );
	if( fp == NULL )
		return;

	png_ptr = png_create_write_struct( PNG_LIBPNG_VER_STRING, NULL, NULL, NULL );
	if( png_ptr == NULL ){
		fclose( fp );
		return;
	}

	info_ptr = png_create_info_struct( png_ptr );
	if( info_ptr == NULL ){
		png_destroy_write_struct( &png_ptr, (png_infopp)NULL);
		fclose( fp );
		return;
	}

	if( setjmp( png_jmpbuf( png_ptr ) ) ){
		png_free_data( png_ptr, info_ptr, PNG_FREE_ALL, -1);
		png_destroy_write_struct( &png_ptr, (png_infopp)NULL);
		fclose( fp );
	}

	png_init_io( png_ptr, fp );
	png_set_IHDR( png_ptr, info_ptr, width, height, 8, PNG_COLOR_TYPE_RGB, PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE );
	png_write_info( png_ptr, info_ptr );
	row = (png_bytep) malloc(3*width*sizeof(png_byte));
	for( y = 0; y < height; y++ ){
		for( x = 0; x < width; x++){
			if(map[y*width+x] == 1){
				row[x*3] = 0;
				row[x*3+1] = 0;
				row[x*3+2] = 0;
			}
			else {
				row[x*3] = 255;
				row[x*3+1] = 255;
				row[x*3+2] = 255;
			}
		}
		png_write_row( png_ptr, row );
	}
	png_write_end( png_ptr, NULL);

	fclose( fp );
	png_free_data( png_ptr, info_ptr, PNG_FREE_ALL, -1);
	png_destroy_write_struct( &png_ptr, (png_infopp)NULL);
	free(row);
	
}

