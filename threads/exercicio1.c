#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <pthread.h>

void *PrintHello(void *arg) {
	pthread_t tid = pthread_self();
	printf("Nova Thread Criada. TID = %u\n", (unsigned int) tid);
	pthread_exit(NULL);
}

int main(int argc, char const *argv[])
{
	pthread_t thread;
	pthread_create(&thread, NULL, PrintHello, NULL);
	pthread_join(thread, NULL);
	pthread_exit(NULL);

	return 0;
}

