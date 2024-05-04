CC=gcc
CFLAGS=-Wall -Wextra
PROGRAM=polar

VPATH=src

all: $(PROGRAM)

$(PROGRAM): main.c
	mkdir build
	$(CC) $(CFLAGS) -o build/$@ $<

clean:
	rm -rf build
