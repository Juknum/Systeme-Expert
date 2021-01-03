############################################################################
##############################    MAKEFILE    ##############################
############################################################################

CC=gcc
CFLAGS= -W -Wall -ansi -pedantic
LDFLAGS=
EXEC=results

SRC= $(wildcard sources/*.c)
OBJ= $(SRC: .c=.o)

results: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

main.o : $(wildcard headers/*.h)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	@rm -rf *.o

mrproper: clean
	@rm -rf $(EXEC)