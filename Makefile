autom: main.o grid.o compute_data.o
	$(CC) -o autom main.o grid.o compute_data.o
main.o: grid.h compute_data.h
	$(CC) -c grid.c main.c compute_data.c
.PHONY: clean

clean:
	-rm *.o 
