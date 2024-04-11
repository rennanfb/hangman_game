#include <map>
#include <string>

namespace hangman {
	void show_clues(const std::map<char, bool>& guessed, std::string& secret_word);
}