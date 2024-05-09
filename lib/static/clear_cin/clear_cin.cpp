#include <iostream>
#include <limits>

#include "clear_cin.h"


void clear_cin() {
    std::cin.clear();
    std::cin.sync();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}