#include "exec_files.h"


void exec_test_1(const char* path){
    //for example run another file with output string //
    pid_t cpid;
    int stat; // process status
    cpid = fork();
    switch (cpid) {
        case -1:
            perror("fork");
            exit(EXIT_FAILURE);
        case 0:
            execv(path, NULL); // against use execvp cuz we doesnt have path to file in $PATH :/
            perror("exec err");
            _exit(EXIT_FAILURE); //buff i/o
        default:
            waitpid(cpid, &stat, 0);
            if (WIFEXITED(stat)){
                printf("DONE!\n");
                exit(EXIT_SUCCESS);
            }
    }
}
