#include "../inc/help.h"

int getPeriod(int argc, char *argv[]) {
    int  period = 0;

    if (argc != 2) {
        std::cerr << "usage: ./child period" << std::endl;
        exit(1);
    }
    try {
        period = std::stoi(argv[1]);
    }
    catch (std::exception& ex) {
        std::cerr << "period should be an integer" << std::endl;
        exit(1);
    }
    if (period < 1 || period > 1000) {
        std::cerr << "period should be in range between 1 and 1000 ms << std::endl;" << std::endl;
        exit(1);
    }
    return period;
}