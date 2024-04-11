#include "letter_exists.hpp"

bool hangman::letter_exists (char guess, std::string& secret_word) {
    for (char letter : secret_word) {
        if(guess == letter) {
            return true;
        }
    } return false;
}