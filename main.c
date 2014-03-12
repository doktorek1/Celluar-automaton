#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include "grid.h"
int main(int argc, char **argv)
{
  int opt;
  int n1, frequency,i;
  char *out = NULL;
    wskaznik pok;
    FILE * in = fopen(argv[1], "r");
	if(in == NULL)
	return EXIT_FAILURE;
    while ((opt = getopt (argc, argv, "n:x:f:t:")) != -1) {
    switch (opt) {
    case 'n':
      
      
      
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
	read_from_file_and_write_to_memory(in);


	for(i = 0; i<n1; i++)
	{
	   if(i%2==1)
		operate(pok->tab1,pok->tab2);
		/*if(i%frequency==0)
			write_picture(pok->tab1);*/
	   else
	 	operate(pok->tab2,pok->tab1);
		/*if(i%frequency==0)
			write_picture(pok->tab2);*/
	}
	return 0;
}
