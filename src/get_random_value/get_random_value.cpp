#include <cstdlib>
#include <ctime>

#include "get_random_value.h"

int get_random_value(int max_value) {
    std::srand(std::time(nullptr)); // use current time as seed for random generator
    return std::rand() % max_value;
}