#include <iostream>
#include <string>

#include "get_user_name.h"
#include "../../lib/static/clear_cin/clear_cin.h"


std::string get_user_name(){
    std::string user_name;

    // Ask about name
    std::cout << "Hi! ";
    do {
        std::cout << "Enter your name, please:" << std::endl;
        std::cin >> user_name;

        if (std::cin.fail()) {
            clear_cin();
            std::cout << "Bad value! Try again" << std::endl;
            continue;
        }
        if (user_name.empty()){
            clear_cin();
            std::cout << "Empty name! Try again" << std::endl;
            continue;
        }
        if (user_name.length() > 20){
            clear_cin();
            std::cout << "The name must be less than 20 symbols! Try again" << std::endl;
            continue;
        }

        break;

    } while(true);

    return user_name;
}