#include<stdio.h>
#include<pthread.h>

int val1 = 0;
int val2 = 0;

void* method1(void* paramater) {
	for(val1 = 0; val1<1000000000; val1++);
	fprintf(stderr, "Thread1 exiting\n");
	return;
}

void* method2(void* parameter) {
	for(val2 = 0; val2<1000000000; val2++);
	fprintf(stderr, "Thread2 exiting\n");
	return;
}

int main() {
	pthread_t thread1, thread2; // Two variables that hold data about each thread.

	pthread_attr_t attr; // Attributes that are used for both threads.
	pthread_attr_init(&attr);
	pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);

	// Start execution of the threads
	pthread_create(&thread1, &attr, method1, NULL);
	pthread_create(&thread2, &attr, method2, NULL);

	// Wait for each thread to finish
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	printf("Val1 is %d, and Val2 is %d\n", val1, val2);

	return 0;
}
