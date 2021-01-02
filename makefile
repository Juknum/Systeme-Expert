############################################################################
##############################    MAKEFILE    ##############################
############################################################################

SOURCES = $(wildcard sources/*.c)
HEADERS = $(wildcard headers/*.h)
CC  = gcc
EXE = results

results: ${SOURCES} ${HEADERS}
	$(CC) ${SOURCES} -o results.exe

# Target to clean up after us
clean:
	-rm -f $(EXE)      # Remove the executable file
	-rm -f $(OBJECTS)  # Remove the object files