CC=gcc -fsanitize=address
CPPFLAGS= 
CLFLAGS= -Wall -Wextra -Werror -std=c99 -O2
LDFLAGS= 
LDLIBS= -lcriterion

SRC= functions.c test.c
OBJ= ${SRC:.c=.o}
DEP= ${SRC:.c=.d}

all: test

-include ${DEP}

test: ${OBJ}

clean:
	rm -rf ${OBJ} ${DEP} test


