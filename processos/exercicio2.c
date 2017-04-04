#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
	pid_t pid;
	for (int i = 0; i <4 ; i++) {
		pid = fork();
		if(pid == 0) { //filho
			printf("Processo filho %u\n", getpid());
			break;
		} else { //pai
			printf("Processo pai %u criou %u\n", getpid(), pid);
		}
	}
	if (pid != 0) wait(NULL);
	return 0;
}