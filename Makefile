CC = clang
CFLAGS = -Wall -Wextra -Werror -Wpedantic

.PHONY: all clean format

all: sorting

sorting: sorting.o insert.o heap.o quick.o batcher.o stats.o
	$(CC) -o sorting sorting.o insert.o heap.o quick.o batcher.o stats.o

sorting.o: sorting.c
	$(CC) $(CFLAGS) -c sorting.c
	
insert.o: insert.c stats.c
	$(CC) $(CFLAGS) -c insert.c stats.c
	
heap.o: heap.c stats.c
	$(CC) $(CFLAGS) -c heap.c stats.c
	
quick.o: quick.c stats.c
	$(CC) $(CFLAGS) -c quick.c stats.c
	
batcher.o: batcher.c stats.c
	$(CC) $(CFLAGS) -c batcher.c stats.c

stats.o: stats.c
	$(CC) $(CFLAGS) -c stats.c

clean:
	rm sorting sorting.o insert.o stats.o heap.o batcher.o quick.o

format:
	clang-format -i -style=file *.{c,h}
	
