#include <iostream>
#include "letter_exists.hpp"
#include "guess_attempt.hpp"

void hangman::guess_attempt(std::map<char, bool>& guessed, std::array<char, 6>& incorrect_guesses, std::string& secret_word, int& incorrect_guesses_number) {
    char guess;
    std::cout << "Type your guess: ";
    std::cin >> guess;

    guessed[guess] = true;

    if (letter_exists(guess, secret_word)) {
        std::cout << "You're right, your guess is in the word! " << std::endl;
    } else {
        std::cout << "Wrong guess, this letter isn't in the word! " << std::endl;
        incorrect_guesses_number++;
        incorrect_guesses[incorrect_guesses_number] = guess;
    }
}