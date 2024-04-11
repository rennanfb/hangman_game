#include <iostream>
#include "show_clues.hpp"

void hangman::show_clues(const std::map<char, bool>& guessed, std::string& secret_word) {
    for(char letter : secret_word) {
        if (guessed.find(letter) != guessed.end()) {
            std::cout << letter << " ";
        } else {
            std::cout << "_ ";
        }
    }
}
