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
    int fd[2];
    pid_t pid;
    char msg[] = "hello from parent\n";
    char buff[100];
    if(pipe(fd) == -1){
        perror("PIPE");
        exit(EXIT_FAILURE);
    }
    pid = fork();
    switch (pid) {
        case -1:
            perror("fork");
            exit(EXIT_FAILURE);
        case 0:
            close(fd[1]); // close write
            read(fd[0],buff,sizeof(buff));
            printf("CHILD getting %s\n",buff);
            close(fd[0]);
            _exit(EXIT_SUCCESS);
        default:
            close(fd[0]);
            write(fd[1],msg, strlen(msg)+1);
            close(fd[1]);
            exit(EXIT_SUCCESS);
            
    }
    
}
