#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h> 
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {

    int num;
    pid_t pid; //Variable que almacenará los id's

    for (num = 0; num < 3; num++) {
        pid = fork(); 
        printf ("Soy el proceso de PID %d y mi padre tiene %d de PID.\n",
                getpid(), getppid());
        if (pid != 0)
            break; // fork devuelve el PID del hijo al proceso padre, mientras que el hijo obtiene pid = 0.
        srandom(getpid());
        sleep(random() % 3);
        printf ("-----------\n");
    }
    if (pid != 0)
        printf("Fin del proceso de PID %d.\n", wait (NULL)); //wait() sirve para que un proceso padre espere a que uno de sus procesos hijos termine antes de continuar su ejecución.

    return 0;
}

 











