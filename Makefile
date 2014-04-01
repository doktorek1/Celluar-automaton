autom: main.o compute_data.o grid.o neighbourhood.o rules.o write_pic.o 
	$(CC) -o autom main.o compute_data.o grid.o neighbourhood.o rules.o write_pic.o -lpng
write_pic.o: write_pic.h
	$(CC) -c write_pic.c 
neighbourhood.o: neighbourhood.h
	$(CC) -c neighbourhood.c
rules.o: rules.h
	$(CC) -c rules.c
main.o: grid.h compute_data.h
	$(CC) -c grid.c main.c compute_data.c 
.PHONY: clean

clean:
	-rm -r *.o 
