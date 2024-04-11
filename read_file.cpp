#include <iostream>
#include <fstream>
#include "read_file.hpp"

std::vector<std::string> hangman::read_file() {
    std::ifstream file;
    file.open("words.txt");

    if(file.is_open()) {
        int amount_words;
        file >> amount_words;

        std::vector<std::string> file_words;

        for (int i = 0 ; i < amount_words ; i++) {
            std::string read_word;
            file >> read_word;
            file_words.push_back(read_word);
        }
        
        file.close();
        return file_words;

    } else {
        std::cout << "Failed to open file" << std::endl;
        exit(0);
    }
}