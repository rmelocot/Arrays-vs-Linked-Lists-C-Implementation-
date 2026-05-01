CC = clang
CFLAGS = -std=c99 -Wall -pedantic -fPIC -I./src

all: lib/libarray.so lib/liblist.so lib/libmem.so bin/test0 bin/atest1

#executable
bin/test0: obj/ltest1.o lib/liblist.so lib/libmem.so
	$(CC) obj/ltest1.o -Llib -llist -lmem -o bin/test0

bin/atest1: obj/atest1.o lib/libarray.so lib/libmem.so
	$(CC) obj/atest1.o -Llib -larray -lmem -o bin/atest1

#object files
obj/atest1.o: src/atest1.c src/array.h src/mem.h
	$(CC) $(CFLAGS) -c src/atest1.c -o obj/atest1.o

obj/ltest1.o: src/ltest1.c src/list.h src/mem.h
	$(CC) $(CFLAGS) -c src/ltest1.c -o obj/ltest1.o

obj/list.o: src/list.c src/list.h src/mem.h
	$(CC) $(CFLAGS) -c src/list.c -o obj/list.o

obj/array.o: src/array.c src/array.h src/mem.h
	$(CC) $(CFLAGS) -c src/array.c -o obj/array.o

obj/mem.o: src/mem.c src/mem.h
	$(CC) $(CFLAGS) -c src/mem.c -o obj/mem.o

#libraries
lib/liblist.so: obj/list.o lib/libmem.so
	$(CC) $(CFLAGS) -shared obj/list.o -Llib -lmem -o lib/liblist.so

lib/libarray.so: obj/array.o lib/libmem.so
	$(CC) $(CFLAGS) -shared obj/array.o -Llib -lmem -o lib/libarray.so

lib/libmem.so: obj/mem.o
	$(CC) $(CFLAGS) -shared obj/mem.o -o lib/libmem.so
clean:
	rm -f obj/*.o

cleaner:
	rm -f obj/*.o lib/*.so bin/*

