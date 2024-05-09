#include <iostream>
#include "src/argument_parse/argument_parse.h"
#include "src/get_random_value/get_random_value.h"
#include "src/check_value/check_value.h"
#include "src/get_user_name/get_user_name.h"
#include "src/result_table/save_result.h"
#include "src/result_table/print_res_table.h"

int main(int argc, char** argv) {
    int mode;
    int value;
    bool error;

    std::tie(mode, value, error) = argument_parse(argc, argv);
    if (error){
        return -1;
    }

    int max_value;
    switch (mode) {
        // Default mode
        case 0:
            max_value = 100;
            break;

        // Max mode
        case 1:
            max_value = value;
            break;

        // Level mode
        case 2:
            switch (value) {
                case 1:
                    max_value = 10;
                    break;
                case 2:
                    max_value = 50;
                    break;
                case 3:
                    max_value = 100;
                    break;
                default:
                    std::cout << "Wrong usage! Level mode requires max_value from 1 to 3!" << std::endl;
                    return -1;
            }
            break;

        // Table mode
        case 3:
            print_res_table();
            std::cout << "Good bye!" << std::endl;
            return 0;

        default:
            std::cout << "Wrong usage! Unknown mode = " << mode << std::endl;
            return -1;
    };

    // Init user_name
    const std::string user_name = get_user_name();

    // Init random max_value
    const int random_value = get_random_value(max_value);

    // Start of guessing
    const int attempts_count =  check_value(random_value);
//    const int attempts_count = 13;

    save_result(user_name, attempts_count);

    std::cout << "Good bye!" << std::endl;
}