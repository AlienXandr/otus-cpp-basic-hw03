#include <iostream>

#include "check_value.h"
#include "../../lib/static/clear_cin/clear_cin.h"


int check_value(const int random_value) {
    int user_value = 0;
    int attempts_count = 0;

    std::cout << "Enter your guess:" << std::endl;
    do {
        attempts_count += 1;
        std::cin >> user_value;

        if (std::cin.fail()) {
            clear_cin();
            std::cout << "Bad value! Try again" << std::endl;
            continue;
        }

        if (user_value < random_value) {
            std::cout << user_value << " ... X ..."  << std::endl;
        }
        else if (user_value > random_value) {
            std::cout << "... X ... " << user_value <<  std::endl;
        }
        else {
            std::cout << "You win!" << std::endl;
            break;
        }

    } while(true);

    return attempts_count;
}