#include <map>
#include <array>
#include <string>

namespace hangman {
	void guess_attempt(std::map<char, bool>& guessed, std::array<char, 6>& incorrect_guesses, std::string& secret_word, int& incorrect_guesses_number);
}