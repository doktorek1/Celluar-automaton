/*taką regułę do Makefile'a wstawić
*calculate_data.o: rules.h neighbourhood.h
	$(CC) -c neighbourhood.c rules.c
*/

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include "grid.h"
#include "neighbourhood.h"
#include "compute_data.h"

char *usage =
  "Usage: %s -s spline-file [-p points-file] [ -g gnuplot-file [-f from_x -t to_x -n n_points ] ]\n"
  "            if points-file is given then\n"
  "               reads discrete 2D points from points-file\n"
  "               writes spline approximation to spline-file\n"
  "               - number of points should be >= 4\n"
  "            else (points-file not given)\n"
  "               reads spline from spline-file\n"
  "            endfi\n"
  "            if gnuplot-file is given then\n"
  "               makes table of n_points within <from_x,to_x> range\n"
  "               - from_x defaults to x-coordinate of the first point in points-file,\n"
  "               - to_x defaults to x-coordinate of the last point\n"
  "               - n_points defaults to 100\n"
  "               - n_points must be > 1\n"
  "            endif\n";

int main(int argc, char **argv)
{
	char *progname= argv[0];
  int opt;
  int n1 = 100, frequency,i;
  char *out = NULL;
	char *inp = NULL;
    	wskaznik glowny;
	sasiedzi stan;
	stan = malloc(sizeof * stan);
	printf("tu dziala1\n");
   
	/**/
printf("tu dziala2\n");
    while ((opt = getopt (argc, argv, "n:x:f:t:")) != -1) {
    switch (opt) {
    case 'n':
      inp = optarg;
       break;
    case 'x':
      n1 = atof(optarg);
      break;
    case 'f':
      frequency = atof(optarg);
      break;
    case 't':
      out = optarg;
      break;
	    default:                   
      printf("%s", usage);//fprintf (stderr, usage, progname);
      exit (EXIT_FAILURE);
    }
  }
	FILE * in = fopen(inp, "r");
	if(in == NULL)
		return EXIT_FAILURE;
	printf("tu dziala3\n");
	glowny = read_from_file_and_write_to_memory(in);
printf("tu dziala4\n");
//printf(" %d %d \n", glowny->wiersze, glowny->kol);
	for(i = 0; i<n1; i++)
	{
	   if(i%2==0){
		operate(glowny, glowny->tab1,glowny->tab2, stan);print_grid(glowny, glowny->tab1);

		/*if(i%frequency==0)*/
			save_BMP(i + 1, glowny, glowny->tab2, out);}
	   else
	 	{operate(glowny, glowny->tab2, glowny->tab1, stan);print_grid(glowny, glowny->tab2);

		/*if(i%frequency==0)*/
			save_BMP(i + 1, glowny, glowny->tab1, out);}
		//printf("\n\n");
	}
	//print_grid(glowny, glowny->tab1);
	//print_grids(glowny, glowny->wiersze, glowny->kol);
	free(stan);
	free(glowny->tab1);
	free(glowny->tab2);
	free(glowny);
	printf("tu dziala5\n");
	return 0;
}
