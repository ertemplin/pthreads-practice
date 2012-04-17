all: threads

threads: threads.c
	gcc -pthread -o threads threads.c

clean:
	rm threads
