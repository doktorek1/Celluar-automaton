/*taką regułę do Makefile'a wstawić
*calculate_data.o: rules.h neighbourhood.h
	$(CC) -c neighbourhood.c rules.c
*/

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include "grid.h"
int main(int argc, char **argv)
{
  int opt;
  int n1, frequency,i;
  char *out = NULL;
	char *inp = NULL;
    wskaznik glowny;
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
    }
  }
	FILE * in = fopen(inp, "r");
	if(in == NULL)
		return EXIT_FAILURE;
	printf("tu dziala3\n");
	glowny = read_from_file_and_write_to_memory(in);
printf("tu dziala4\n");

	for(i = 0; i<n1; i++)
	{
	   if(i%2==0)
		operate(glowny, glowny->tab1,glowny->tab2);
		/*if(i%frequency==0)
			write_picture(glowny->tab1);*/
	   else
	 	operate(glowny, glowny->tab2,glowny->tab1);
		/*if(i%frequency==0)
			write_picture(glowny->tab2);*/
	}
	//print_grids(glowny, glowny->wiersze, glowny->kol);
	printf("tu dziala5\n");
	return 0;
}
