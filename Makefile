FLAGS=-Wextra -Wall -Werror -pedantic -std=c99

all: start

start: main.o linearlist.o
	gcc $(FLAGS) -o lab26 main.o linearlist.o

main.o: main.c
	gcc -c $(FLAGS) main.c

linearlist.o: linearlist.h linearlist.c
	gcc -c $(FLAGS) linearlist.h linearlist.c

clean:
	-rm -f *.o *.gch lab26