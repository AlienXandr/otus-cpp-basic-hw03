#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

#include "print_res_table.h"


void print_res_table(){
    const std::string res_table_filename = "result_table.txt";

    std::fstream out_file{res_table_filename};
    if (!out_file.is_open()) {
        std::cout << "Failed to open file for write: " << res_table_filename << "!" << std::endl;
        return;
    }

    std::cout << std::left << std::setw(20) << "Name" << std::setw(10) << "Last res" << std::setw(25) << "Last date" << std::setw(10)<< "Best res" << std::setw(25) << "Best date" << std::endl;

    std::string s;
    std::stringstream ss;
    std::string token;
    std::vector<std::string> tokens;
    char delimiter = ' ';

    while (std::getline(out_file, s)){
        if(!s.empty()){
            ss.clear();
            tokens.clear();
            ss.str(s);
            while (getline(ss, token, delimiter)) {
                tokens.push_back(token);
            }
            std::cout << std::left << std::setw(20) << tokens[0] << std::setw(10) << tokens[1] << std::setw(25) << tokens[2] << std::setw(10) << tokens[3] << std::setw(25) << tokens[4] << std::endl;
        }
    }
}