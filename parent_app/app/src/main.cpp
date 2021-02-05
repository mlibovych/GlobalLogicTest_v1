#include <iostream>
#include <fstream>
#include <stdexcept>
#include <chrono>
#include <thread>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>

#include "help.h"


int main(int argc, char *argv[]) {   
    int period = getPeriod(argc, argv); //get delay
    std::ofstream f(".counterfile.txt");

    std::cout << "Hi, I am parent process" << std::endl;
    f << 0; //start counter;
    f.close();
    while (1) {
        pid_t pid, wpid;
        int status;

        pid = fork(); //start new proc
        if (pid == 0) {
            char *args[]  = {"./child", argv[1], NULL};
            if (execvp(args[0], args) == -1) {
                perror("Process failed");
            }
            exit(EXIT_FAILURE);
        }
        else if (pid < 0) {
            perror("fork error");
        }
        else {
            do {
                wpid = waitpid(pid, &status, WUNTRACED); //wate until child proc terminated
            }
            while (!WIFEXITED(status) && !WIFSIGNALED(status));
        }
    }
    return 0;
}