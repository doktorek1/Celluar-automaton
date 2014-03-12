autom: main.o grid.o calculate_data.o
	$(CC) -o autom main.o grid.o calculate_data.o
main.o: grid.h calculate_data.h
	$(CC) -c grid.c main.c calculate_data.c
.PHONY: clean

clean:
	-rm *.o 
