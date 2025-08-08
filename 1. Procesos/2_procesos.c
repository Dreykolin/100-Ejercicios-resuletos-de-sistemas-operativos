#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
    int num;
    pid_t pid;

    srandom(getpid());
    for (num = 0; num < 3; num++){
        pid = fork();
        printf("Soy el proceso de PID %d, y mi padre tiene %d de PID.\n",
                getpid(), getppid());
        if(pid == 0)   //A diferencia del código anterior, la condición es distinta. Esto hace que el proceso raiz sea quien esté dentro del bucle y los hijos que se generan, salgan de éste.
            break;
    }
    if(pid == 0)
        sleep(random() % 5);  //solo es para que no se printee de golpe.
    else
        for(num = 0; num < 3; num++){
            printf("Fin del proceso de PID %d. \n", wait(NULL));  //Entonces cuando el proceso raiz salga del bucle, vendrá a esta casilla del código y hará print de sus hijos.
        }
    return 0;
}
