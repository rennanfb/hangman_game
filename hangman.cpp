#include "letter_exists.hpp"
#include "incorrect.hpp"
#include "show_header.hpp"
#include "show_mistakes.hpp"
#include "show_clues.hpp"
#include "guess_attempt.hpp"
#include "read_file.hpp"
#include "draw_words.hpp"
#include "save_file.hpp"
#include "add_word.hpp"

static std::string secret_word;
static std::map<char, bool> guessed;
static std::array<char, 6> incorrect_guesses;
static int incorrect_guesses_number = 0;

int main() {

    show_header();
    hangman::draw_words(secret_word);

    while (hangman::incorrect(secret_word, guessed) && incorrect_guesses_number < 6) {
        hangman::show_mistakes(incorrect_guesses, incorrect_guesses_number);
        hangman::show_clues(guessed, secret_word);
        std::cout << std::endl;
        hangman::guess_attempt(guessed, incorrect_guesses, secret_word, incorrect_guesses_number);
    }
    std::cout << "The secret word was " << secret_word << std::endl;
    if (hangman::incorrect(secret_word, guessed)) {
        std::cout << "You get hanged, but you can try again !" << std::endl;
    }
    else {
        std::cout << "You get the word, Congratulations !" << std::endl;
        std::cout << "Do you want to add a new word to the secret word list? (Y/N)" << std::endl;
        char add_answer;
        std::cin >> add_answer;
        if (add_answer == 'Y') {
            hangman::add_word();
            std::cout << "Thank you for playing !" << std::endl;
        } else {
            std::cout << "Thank you for playing !" << std::endl;
        }
    }
}