#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <png.h>
#include "grid.h"
/*void make_image(wskaznik pop , char name[],int lp)
	{
	int i,c;
	char buffer[60];
	c = sprintf(buffer, "%s%d.bmp", name, lp);
	int n = pop->wiersze, m = pop->kol ;
	allegro_init();
	set_color_depth( 16 );
	BITMAP *image = create_bitmap( 15*n, 15*m );
	PALETTE pal;
	
		if( image )
			{
    			clear_to_color( image , makecol( 255 , 255 , 255 ) );
			for(i=0;i<pop->kol*pop->wiersze;i++)
				{
				rectfill( image , pop->c[i].x*15 , pop->c[i].y*15 , pop->c[i].x*15+15 , pop->c[i].y*15+15, makecol( 0 ,  0 , 0 ) );
				}
			save_bitmap( name , image , pal );
    			destroy_bitmap( image );
			}
	allegro_exit();
	}*/
void save_BMP(int lp, wskaznik glowny, int *map, char *nazwa_pliku, int ppp)
{
	int n,h,u,t;
	char buffer[60];
	n = sprintf(buffer, "%s%d.png", nazwa_pliku, lp);
	char *filename;
	filename  = buffer;
	//Wypisywanie---------------------------
	printf("Utworzono:  ");
	puts(buffer);
	//--------------------------------------
	int width = glowny->kol, height = glowny->wiersze;
	int x, y, i, j;
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
	png_set_IHDR( png_ptr, info_ptr, ppp*width,ppp*height, 8, PNG_COLOR_TYPE_RGB, PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE );
	png_write_info( png_ptr, info_ptr );
	row = (png_bytep) malloc(3*ppp*width*sizeof(png_byte));
	for( y = 0; y < height; y++ ){
		for( x = 0; x < width; x++){
			//for(i=0;i<p;i++)//{//tu
				if(map[y*width+x] == 0)
				for(i=0;i<ppp;i++){
				row[x*ppp+i] = 0;
				//row[i*x+1+i*3] = 0;
				//row[i*x+2+i*3] = 0;
				}
				else {for(j=0;j<ppp;j++)
				row[x*ppp+j] = 255;
				//row[i*x+1+i*3] = 255;
				//row[i*x+2+i*3] = 255;
				}
			//}//tu
		}
		for( h = 0; h < ppp; h++)
		png_write_row( png_ptr, row );
	}
	png_write_end( png_ptr, NULL);

	fclose( fp );
	png_free_data( png_ptr, info_ptr, PNG_FREE_ALL, -1);
	png_destroy_write_struct( &png_ptr, (png_infopp)NULL);
	free(row);	
}

