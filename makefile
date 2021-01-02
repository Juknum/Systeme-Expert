# Makefile used for compilation

SRC = $(wildcard projet/*.c)
HDR = $(wildcard headers/*.h)
COMPILE = gcc -o projet/main.o projet/main.c

.PHONY: create
.PHONY: clean

create: ${SRC} ${HDR}
	${COMPILE} ${SRC} ${HDR}

clean:
	rm *.o