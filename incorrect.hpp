#include <string>
#include <map>

namespace hangman {
	bool incorrect(std::string& secret_word, const std::map<char, bool>& guessed);
}