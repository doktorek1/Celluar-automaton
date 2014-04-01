#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <png.h>
#include "grid.h"
void save_BMP(int lp, wskaznik glowny, int *map, char *nazwa_pliku)
{
	int n;
	char buffer[60];
	n = sprintf(buffer, "%s%d.png", nazwa_pliku, lp);
	char *filename;
	filename  = buffer;
	puts(buffer);
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

