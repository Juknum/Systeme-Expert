# Makefile used for compilation

CC=gcc
CFLAGS= -W -Wall -ansi -pedantic
LDFLAGS=
EXEC=launch

SRC= $(wildcard projet/*.c)
HDR = $(wildcard headers/*.h)
OBJ= $(SRC: .c=.o)

all: $(EXEC)

launch: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

main.o : ${HDR}

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	@rm -rf *.o

mrproper: clean
	@rm -rf $(EXEC)