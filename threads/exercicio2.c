#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <pthread.h>

#define MAX_THREADS 5

void *PrintHello(void *arg) {
	pthread_t tid = pthread_self();
	printf("Nova Thread Criada. TID = %u\n", (unsigned int) tid);
	pthread_exit(NULL);
}

int main(int argc, char const *argv[])
{
	pthread_t thread[MAX_THREADS];
	int i;
	for(i = 0; i < MAX_THREADS; i++) {
		pthread_create(&thread[i], NULL, PrintHello, NULL);
	}
	for(i = 0; i < MAX_THREADS; i++) {
		pthread_join(thread[i], NULL);
	}
	pthread_exit(NULL);
	return 0;
}

