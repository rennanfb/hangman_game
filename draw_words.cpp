#include <vector>
#include <cstdlib>
#include <ctime>
#include "read_file.hpp"
#include "draw_words.hpp"

void hangman::draw_words(std::string& secret_word) {
    std::vector<std::string> words = read_file();

    srand(time(NULL));
    int drawn_index = rand() % words.size();

    secret_word = words[drawn_index];
}