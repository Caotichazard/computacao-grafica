CC=gcc
CFLAGS=-lm -lX11
DEPS = util.h linklist.h cg2d.h
OBJ = main.o whereismymouse.o cg2d.o linklist.o util.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $<

main: $(OBJ)
	$(CC) -o $@ $^ bibaux.o $(CFLAGS)