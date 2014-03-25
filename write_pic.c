#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <allegro.h>
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
	char pom[50];// = malloc ( 50 * sizeof ( char ) );
	int *buffer = tab; 
	char *numer_w_nazwie = zamien_na_napis( lp );
	//pom = ( char * ) realloc(nazwa_pliku, (strlen(nazwa_pliku) + daj_ilosc_cyfr_w_liczbie(lp)) * sizeof ( char ));
	strcpy(pom, nazwa_pliku);
	strcat(pom, numer_w_nazwie);
	int pozycja_x, pozycja_y;
	int i, j;
	//int skala= (int) 400/s->kolumny;
	

	//nazwa[strlen(nazwa)-3] = '0' + (int) lp_pliku/100;
	//nazwa[strlen(nazwa)-2] = '0' + (int) (lp_pliku/10)%10;
	//nazwa[strlen(nazwa)-1] = '0' + (int) lp_pliku%10;


	/*allegro_init();
	set_color_depth(16);
	set_pallete(black_palette);
	BITMAP *obrazek  = create_bitmap(glowny->kol, glowny->wiersze);
	clear_to_color(obrazek, makecol( 255, 255, 255 ));


	for( pozycja_x = 0; pozycja_x < glowny->kol; pozycja_x++)
		for( pozycja_y = 0; pozycja_y < s->wiersze; pozycja_y++)
			putpixel(obrazek, pozycja_x * skala + i, pozycja_y * skala + j, makecol(0,0,0));
			//if ( s->wektor[ pozycja_y * s->kolumny + pozycja_x] == 1)
				//for(i=0; i<skala; i++)
					//for(j=0; j<skala; j++)
						


	save_bitmap("bmp/123.bmp", obrazek, default_palette);

	destroy_bitmap(obrazek);
*/


































	/*title = pom;
	int width = glowny->kol;
	int height = glowny->wiersze;
	  int code = 0;
   FILE *fp;
   png_structp png_ptr;
   png_infop info_ptr;
   png_bytep row;
 fp = fopen(filename, "wb");
   if (fp == NULL) {
      fprintf(stderr, "Could not open file %s for writing\n", filename);
      code = 1;
      goto finalise;
   }
   png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
   if (png_ptr == NULL) {
      fprintf(stderr, "Could not allocate write struct\n");
      code = 1;
      goto finalise;
   }

   // Initialize info structure
   info_ptr = png_create_info_struct(png_ptr);
   if (info_ptr == NULL) {
      fprintf(stderr, "Could not allocate info struct\n");
      code = 1;
      goto finalise;
   }
 if (setjmp(png_jmpbuf(png_ptr))) {
      fprintf(stderr, "Error during png creation\n");
      code = 1;
      goto finalise;
   }
   png_init_io(png_ptr, fp);

   // Write header (8 bit colour depth)
   png_set_IHDR(png_ptr, info_ptr, width, height,
         8, PNG_COLOR_TYPE_RGB, PNG_INTERLACE_NONE,
         PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);

   // Set title
   if (title != NULL) {
      png_text title_text;
      title_text.compression = PNG_TEXT_COMPRESSION_NONE;
      title_text.key = "Title";
      title_text.text = title;
      png_set_text(png_ptr, info_ptr, &title_text, 1);
   }

   png_write_info(png_ptr, info_ptr);
  // Allocate memory for one row (3 bytes per pixel - RGB)
   row = (png_bytep) malloc(3 * width * sizeof(png_byte));

   // Write image data
   int x, y;
   for (y=0 ; y<height ; y++) {
      for (x=0 ; x<width ; x++) {
         setRGB(&(row[x*3]), buffer[y*width + x]);
      }
      png_write_row(png_ptr, row);
   }

   // End write
   png_write_end(png_ptr, NULL);
   finalise:
   if (fp != NULL) fclose(fp);
   if (info_ptr != NULL) png_free_data(png_ptr, info_ptr, PNG_FREE_ALL, -1);
   if (png_ptr != NULL) png_destroy_write_struct(&png_ptr, (png_infopp)NULL);
   if (row != NULL) free(row);

   //return code;
}*/
	//puts(pom);
	//printf("\n");

	
}

