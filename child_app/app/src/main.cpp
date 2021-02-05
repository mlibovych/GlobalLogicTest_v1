#include <iostream>
#include <stdexcept>
#include <chrono>
#include <thread>
#include <stdlib.h>
#include <fstream>

#include "help.h"


int main(int argc, char *argv[]) {   
    int period = getPeriod(argc, argv);
    std::ifstream in(".counterfile.txt");
    int counter = 0;

    std::cout << "Hi, I am child process" << std::endl;
    in >> counter;
    in.close();
    while (1) {
        std::cout << counter++ << std::endl;
        std::ofstream out(".counterfile.txt");
        out << counter;
        out.close();
        std::this_thread::sleep_for(std::chrono::milliseconds(period));
    }
    return 0;
}