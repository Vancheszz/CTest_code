#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
//#include "pid_test.h"
#include "exec_files.h"
int main(int argc, const char * argv[]) {
    //test pid
    //testing_pid();
    //pipe_fork();
    if (argc != 2 ){
        printf("usage: app path");
    }else{
        exec_test_1(argv[1]);
    }
    return EXIT_SUCCESS;
}
