CC=gcc -fsanitize=address
CPPFLAGS= 
CLFLAGS= -Wall -Wextra -Werror -std=c99 -O2
LDFLAGS= 
LDLIBS= -lcriterion

SRC= functions.c main.c
OBJ= ${SRC:.c=.o}
DEP= ${SRC:.c=.d}

all: main

-include ${DEP}

main: ${OBJ}

clean:
	rm -rf ${OBJ} ${DEP} main


