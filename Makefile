.PHONY: all clean

CC := cc
CCFLAGS := -O3

all: ecas

ecas: ecas.o

ecas.o: ecas.c
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	rm ecas ecas.o