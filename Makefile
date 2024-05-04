CC=gcc
CFLAGS=-Wall -Wextra
PROGRAM=polar

VPATH=src

outs = main.o new.o
sources= main.c new.c

all: $(PROGRAM)

$(PROGRAM): $(outs)
	mkdir build
	$(CC) $(CFLAGS) -o build/$@ $^

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<
clean:
	rm -rf build
	rm $(outs)

main.o: polar.h 
new.o: polar.h
