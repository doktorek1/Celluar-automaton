#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include "grid.h"
#include "neighbourhood.h"
#include "compute_data.h"


int main(int argc, char **argv)
{
	char *usage =
   "           Parametres on start:\n"
  "             -n [filename] - generation on the beginning\n"
  "             -x [number] - number of generations to generate\n"
  "             If not, default value is 100.\n"
  "		-j [number] - zoom\n"
  "		If not, default value is 5\n"
  "             -t [filename] - name of the graphical file to save generations. \n"
  "             If not, default is <Generacja>\n"
  "		-f [number] - frequency of saving to grafical files of generations\n"
  "		If not, default value is 1\n"
  "             -l [filename] - filename in *.txt format to save last generation of cells\n"
  "             If not, then no file will be saved on disk.\n\n\n"
  "             NOW RESTART THE PROGRAM CORRECTLY! \n\n\n";
	if(argc == 1)     
		{          
		printf("Starting program: %s\n", argv[0]);    
		puts(usage);
        	return EXIT_SUCCESS;
	
		}
  	int opt;
  	int n1 = 100, frequency = 1,i,q=5;
  	char *out = "Generacja";
	char *inp = NULL;
	char *zapis = NULL;
    	wskaznik glowny;
	sasiedzi stan;
	stan = malloc(sizeof * stan);
		
    while ((opt = getopt (argc, argv, "n:x:f:t:l:j:")) != -1) {
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
    case 'l':
      zapis = optarg;
      break;
    case 'j':
      q = atoi(optarg);
      break;
	
	    
    }
  }
	FILE * in = fopen(inp, "r");
	if(in == NULL)
		{
		fprintf(stderr, "Nie mogę czytać pliku!!!. Koniec prograamu!!!\n");
		return EXIT_SUCCESS;
		}
	
	glowny = read_from_file_and_write_to_memory(in);
	fclose(in);

	for(i = 0; i<n1; i++)
	{
	   if(i%2==0){
		operate(glowny, glowny->tab1,glowny->tab2, stan);
			if( i % frequency == 0 )
				save_BMP(i + 1, glowny, glowny->tab2, out,q);
		}
	   else
	 	{operate(glowny, glowny->tab2, glowny->tab1, stan);
			if( i % frequency == 0 )
				save_BMP(i + 1, glowny, glowny->tab1, out,q);

		}
		
	
	}

	if(zapis != NULL){
		if(i % 2 == 1)
			save_last_generation(glowny, glowny->tab1, zapis);
		else
			save_last_generation(glowny, glowny->tab2, zapis);
		printf("Zapisano ostatnia generacje do pliku!\n");
	}
	free(stan);
	free(glowny->tab1);
	free(glowny->tab2);
	free(glowny);
	printf("tu dziala5\n");
	return EXIT_SUCCESS;
}
