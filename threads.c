#include<stdio.h>
#include<pthread.h>

int val1 = 0;
int val2 = 0;

int method1() {
	for(val1 = 0; val1<1000000000; val1 += 2);
	fprintf(stderr, "Thread1 exiting\n");
	return val1;
}

int method2() {
	for(val2 = 0; val2<1000000000; val2++);
	fprintf(stderr, "Thread2 exiting\n");
	return val2;
}

int main() {


	pthread_t thread1, thread2;

	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);

	pthread_create(&thread1, &attr, *method1, NULL);
	pthread_create(&thread2, &attr, *method2, NULL);

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	printf("Val1 is %d, and Val2 is %d\n", val1, val2);

	return 0;
}
