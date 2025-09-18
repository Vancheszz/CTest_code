#include "signal.h"
pid_t child_pid = 0; // global for handler
void handler_timeout(int sig){ //kill process
    if (sig == SIGALRM && child_pid > 0){
        printf("Kill %d\n", child_pid);
        kill(child_pid, SIGKILL);
    }
}
void signal_test(int time){
    signal(SIGALRM,handler_timeout);
    int status,res;
    child_pid = fork();
    switch(child_pid){
        case -1:
            exit(EXIT_FAILURE);
        case 0:
            sleep(time);
            _exit(EXIT_SUCCESS);
        default:
            res = waitpid(child_pid, &status, WNOHANG);
            alarm(time/2);
            while(1){
                if(res == 0){
                    sleep(1); //some work i parent
                }else if(res == child_pid){
                    printf("Process was done)\n");
                    exit(EXIT_SUCCESS);
                }else{
                    printf("err");
                    exit(EXIT_FAILURE);
                }
            }
    }
}

void multiple_pids(int pnum){
    pid_t child_pnum[pnum];
    int fork_count = pnum;
    for (int i =0; i < pnum; i++){
        child_pnum[i] = fork();
        if(child_pnum[i] == -1){
            perror("ERROR FORK");
            exit(EXIT_FAILURE);
        }
    }
    
    
}
