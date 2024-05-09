#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>

#include "save_result.h"
#include "../../lib/dynamic/datetime/datetime.h"

void save_result(const std::string& user_name, const int attempts_count){
    const std::string res_table_filename = "result_table.txt";

    std::fstream file{res_table_filename};
    if (!file.is_open()) {
        file.clear();
        file.open(res_table_filename, std::ios::out); // create file
    }

    std::string s;
    std::string::size_type n = -1;
    // Find user_name in result_table
    while (std::getline(file, s)){
        if(!s.empty()){
            n = s.find(user_name, 0);
            if (n != std::string::npos){
                // user_name in result_table
                break;
            }
        }
    }

    std::string result;
    int last_res = attempts_count;
    std::string date_last_res = getCurrentDateTime();
    int best_res = last_res;
    std::string date_best_res = date_last_res;

    // user_name in result_table
    if (n != std::string::npos){
        // Create a stringstream object with the input string
        std::stringstream ss(s);
        // Tokenize the input string by space delimiter
        std::string token;
        std::vector<std::string> tokens;
        char delimiter = ' ';
        while (getline(ss, token, delimiter)) {
            tokens.push_back(token);
        }

        best_res = std::stoi(tokens[3]);
        date_best_res = tokens[4];
        if (last_res < best_res){
            best_res = last_res;
            date_best_res = date_last_res;
        }

        unsigned int pos = file.tellp();
        file.seekp(pos - 60 - 1, std::ios::beg);
    } else{
        file.clear();
        file.seekp(0, std::ios::end);
    }

    result = user_name + " " + std::to_string(last_res) + " " + date_last_res
             + " " + std::to_string(best_res) + " " + date_best_res;

    // Alignment of lines up to 60 symbols
    while (result.length() < 60){
        result += " ";
    }
    // Append new results to the table:
    file << result << std::endl;
    file.close();

    // Print result
    std::cout << std::left << std::setw(20) << "Name" << std::setw(10) << "Last res" << std::setw(25) << "Last date" << std::setw(10)<< "Best res" << std::setw(25) << "Best date" << std::endl;
    std::cout << std::left << std::setw(20) << user_name << std::setw(10) << last_res << std::setw(25) << date_last_res << std::setw(10) << best_res << std::setw(25) << date_best_res << std::endl;
}