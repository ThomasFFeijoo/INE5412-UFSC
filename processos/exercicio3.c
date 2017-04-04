#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char **argv) {
    int i, j;
    pid_t pid, pid2;

    for(i = 0; i < 2; i++) {
     	pid = fork();
     	
        if (pid == 0) { //filho
            
            for(j = 0; j < 2; j++) {
                pid2 = fork();

                if (pid2 == 0) break; //filho
            }
            
            printf("%d Processo %u filho de %u \n", j,getpid(), getppid());
            break;
     	}
            
        if (pid2 != 0) wait(NULL); //pai (2 nivel da arvore) espera os filhos
    }
	
    if (pid != 0) wait(NULL); //pai (1 nivel da arvore) espera os filhos terminarem
    
    return 0;
}