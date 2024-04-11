#include <iostream>
#include "show_mistakes.hpp"

void hangman::show_mistakes(std::array<char, 6>& incorrect_guesses, int& incorrect_guesses_number) {
    if(incorrect_guesses_number >= 1) {
        std::cout << "Wrong Letters: ";
        for(char letter : incorrect_guesses) {
            std::cout << letter << " " ;
        }std::cout << "..." << std::endl;
    }
}