#include <iostream>
#include <vector>
#include "read_file.hpp"
#include "save_file.hpp"
#include "add_word.hpp"

void hangman::add_word() {
    std::cout << "Type the new word, using uppercase letters" << std::endl;
    std::string new_word;
    std::cin >> new_word;

    std::vector<std::string> new_list = read_file();
    new_list.push_back(new_word);

    save_file(new_list);
    std::cout << "You added the word " << new_word << " to the secret list!" << std::endl;
}