CC=gcc
CFLAGS=-Werror -Wall
SOURCE=main.c ft_putchar.c ft_atoi.c 

all:
	$(CC) $(CFLAGS) -o ./ex00/rush-00 -g ${SOURCE} rush00.c  
	$(CC) $(CFLAGS) -o ./ex00/rush-01 -g ${SOURCE} rush01.c
	$(CC) $(CFLAGS) -o ./ex00/rush-02 -g ${SOURCE} rush02.c
	$(CC) $(CFLAGS) -o ./ex00/rush-03 -g ${SOURCE} rush03.c
	$(CC) $(CFLAGS) -o ./ex00/rush-04 -g ${SOURCE} rush04.c

clean:
	rm -rf *.dSYM *~ *.o

fclean: clean
	rm ./ex00/rush-00 ./ex00/rush-01 ./ex00/rush-02 ./ex00/rush-03 ./ex00/rush-04

run:
	./a.out
