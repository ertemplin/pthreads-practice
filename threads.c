#include<stdio.h>
#include<pthread.h>

int numThreads = 8;

int values[200] = {0};

void* task(void* threadNumber) {
	int number = (int)threadNumber;
	fprintf(stderr, "Thread starting: %d\n", number);
	for(values[number] = 0; values[number]<1000000000; values[number]++);
	fprintf(stderr, "Thread %d exiting\n", number);
	pthread_exit(NULL);
}

int main(int argc, char** argv) {
	if(argc>1) {
		numThreads = atoi(argv[1]);
		if(numThreads > 200) {
			fprintf(stderr, "Too many threads! Please keep number of threads below 200!\n");
			exit(1);
		}
	}

	pthread_t threads[numThreads]; // Variables that hold data about each thread.

	pthread_attr_t attr; // Attributes that are used for all threads.
	pthread_attr_init(&attr);
	pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);

	// Start execution of the threads
	int i;
	for(i = 0; i<numThreads; i++) {
		pthread_create(&threads[i], &attr, task, (void*)i);
	}

	// Wait for each thread to finish
	int j;
	for(j = 0; j<numThreads; j++) {
		pthread_join(threads[j], NULL);
	}

	for(i = 0; i<numThreads; i++) {
		printf("Value for thread%d is %d\n", i, values[i]);
	}

	return 0;
}
