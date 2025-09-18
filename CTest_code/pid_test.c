#include "pid_test.h"

void testing_pid(void){
    pid_t pid = fork();
    if(signal(SIGCHLD, SIG_IGN) == SIG_ERR){
        perror("signal");
        exit(EXIT_FAILURE);
    }
    //switch values from fork
    switch (pid) {
        case -1:
            puts("FORK error\n");
            perror("FORK");
            exit(EXIT_FAILURE);
        case 0:
            //child code here...
            puts("Hello from child");
            fflush(stdout); // stdout buffer moment
            _exit(EXIT_SUCCESS);
        default:
            printf("CHILD is PID %jd\n", (intmax_t) pid);
            exit(EXIT_SUCCESS);

    }
}
void pipe_fork(void){
    //...
}
