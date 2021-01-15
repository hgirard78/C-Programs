CC=gcc
CPPFLAGS= 
CLFLAGS= -Wall -Wextra -Werror -std=c99 -O1
LDFLAGS= 
LDLIBS= -lcriterion

SRCMAIN= main.c functions.c
SRCTEST= functions_test.c test.c

OBJMAIN= ${SRCMAIN: .c=.o}
OBJTEST= ${SRCTEST: .c=.o}

all: main test

test: ${OBJTEST} 

main: ${OBJMAIN}

clean: testclean mainclean

testclean:
	${RM} ${OBJTEST}
	${RM} test
mainclean:
	${RM} ${OBJMAIN}
	${RM} main

