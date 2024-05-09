#include <iostream>
#include "argument_parse.h"


std::tuple<int, int, bool> argument_parse(int argc, char** argv){
    int mode{0};
    int value{0};
    bool error{false};

    if (argc >= 2) {
        std::string parameter{argv[1]};

        if (parameter == "-max") {
            if (argc < 3) {
                error = true;
                std::cout << "Wrong usage! The argument '-max' requires some value!" << std::endl;
                return std::make_tuple(mode, value, error);
            }
            mode = 1;
            value = std::stoi(argv[2]);
            if (value < 3 || value > 100000){
                error = true;
                std::cout << "Wrong usage! The argument '-max' requires value from 3 to 100_000!" << std::endl;
                return std::make_tuple(mode, value, error);
            }
        }
        else if (parameter == "-level") {
            if (argc < 3) {
                error = true;
                std::cout << "Wrong usage! The argument '-level' requires some value!" << std::endl;
                return std::make_tuple(mode, value, error);
            }
            mode = 2;
            value = std::stoi(argv[2]);
            if (value < 1 || value > 3){
                error = true;
                std::cout << "Wrong usage! The argument '-level' requires value from 1 to 3!" << std::endl;
                return std::make_tuple(mode, value, error);
            }
        }
        else if (parameter == "-table") {
            mode = 3;
        }
        else {
            error = true;
            std::cout << "Wrong usage! Unknown argument = " << argv[1] << std::endl;
        }
    }

    return std::make_tuple(mode, value, error);
}