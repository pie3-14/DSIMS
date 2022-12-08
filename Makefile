dsmis: main.o cmd.o parse.o
	gcc main.o cmd.o parse.o -o dsmis

main.o: main.c parse.h
	gcc -c -o main.o main.c

cmd.o: cmd.c cmd.h
	gcc -c -o cmd.o cmd.c

parse.o: parse.c parse.h cmd.h
	gcc -c -o parse.o parse.c

clean:
	rm *.o dsmis