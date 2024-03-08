#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

string secret_word;

map<char, bool> guessed;

vector<char> incorrect_guesses;

bool letter_exists (char guess) {
    for (char letter : secret_word) {
        if(guess == letter) {
            return true;
        }
    } return false;
}

bool incorrect() {
    for (char letter : secret_word) {
        if(!guessed[letter]) {
            return true;
        }
    } return false;
}

bool not_hanged() {
    return incorrect_guesses.size() < 6;
}

void show_header() {
    cout << endl;
    cout << "*********************************" << endl;
    cout << "** Welcome to the Hangman Game **" << endl;
    cout << "*********************************" << endl;
    cout << endl;
    cout << "You have 6 attempts before get hanged, good luck !" << endl;
}

void show_mistakes() {
    if(incorrect_guesses.size() >= 1) {
        cout << "Wrong Letters: ";
        for(char letter : incorrect_guesses) {
            cout << letter << " " ;
        }cout << "..." << endl;
    }
}

void show_clues() {
    for(char letter : secret_word) {
        if (guessed[letter]) {
            cout << letter << " ";
        } else {
            cout << "_ ";
        }
    }
}

void guess_attempt () {
    char guess;
    cout << "Type your guess: ";
    cin >> guess;

    guessed[guess] = true;

    if (letter_exists(guess)) {
        cout << "You're right, your guess is in the word! " << endl;
    } else {
        cout << "Wrong guess, this letter isn't in the word! " << endl;
        incorrect_guesses.push_back(guess);
    }
}

vector<string> read_file() {
    ifstream file;
    file.open("words.txt");

    if(file.is_open()) {
        int amount_words;
        file >> amount_words;

        vector<string> file_words;

        for (int i = 0 ; i < amount_words ; i++) {
            string read_word;
            file >> read_word;
            file_words.push_back(read_word);
        }
        
        file.close();
        return file_words;

    } else {
        cout << "Failed to open file" << endl;
        exit(0);
    }
}

void draw_words() {
    vector<string> words = read_file();

    srand(time(NULL));
    int drawn_index = rand() % words.size();

    secret_word = words[drawn_index];
}

void save_file(vector<string> new_list) {
    ofstream file;
    file.open("words.txt");
    if(file.is_open()) {
        file << new_list.size() << endl;

        for(string word : new_list) {
            file << word << endl;
        }
    } else {
        cout << "Failed to open file" << endl;
        exit(0);
    }
    file.close();
}

void add_word() {
    cout << "Type the new word, using uppercase letters" << endl;
    string new_word;
    cin >> new_word;

    vector<string> word_list = read_file();
    word_list.push_back(new_word);

    save_file(word_list);
    cout << "You added the word " << new_word << " to the secret list!" << endl;
}

void endgame() {
    cout << "The secret word was " << secret_word << endl;
    if (incorrect()) {
        cout << "You get hanged, but you can try again !" << endl;
    } else {
        cout << "You get the word, Congratulations !" <<endl;
        cout << "Do you want to add a new word to the secret word list? (Y/N)" << endl;
        char add_answer;
        cin >> add_answer;
        if (add_answer == 'Y') {
            add_word();
            cout << "Thank you for playing !" << endl;
        }
    }
}

int main() {

    show_header();
    draw_words();

    while (incorrect() && not_hanged()) {

        show_mistakes();
        show_clues();
        cout << endl;
        guess_attempt();
    }
    endgame();
}