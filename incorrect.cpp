#include "incorrect.hpp"

bool hangman::incorrect(std::string& secret_word, const std::map<char, bool>& guessed) {
    for (char letter : secret_word) {
        if(guessed.find(letter) == guessed.end()) {
            return true;
        }
    } return false;
}
