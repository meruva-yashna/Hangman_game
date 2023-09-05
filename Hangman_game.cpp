#include <iostream>
#include <string>
#include <vector>
using namespace std;

class HangmanWord {
private:
    string secretWord;
    string guessedWord;

public:
    HangmanWord(const string& word) : secretWord(word) {
        guessedWord = string(secretWord.length(), '_');
    }

    bool guess(char letter) {
        bool correctGuess = false;
        for (int i = 0; i < secretWord.length(); ++i) {
            if (secretWord[i] == letter) {
                guessedWord[i] = letter;
                correctGuess = true;
            }
        }
        return correctGuess;
    }

    bool isWordGuessed() const {
        return secretWord == guessedWord;
    }

    string getGuessedWord() const {
        return guessedWord;
    }
};

class HangmanFigure {
public:
    void draw(int incorrectGuesses) {
        vector<string> figure = {
    "  ____",
    " |    |",
    " |    " + string(incorrectGuesses > 0 ? "O" : ""),
    " |   " + string(incorrectGuesses > 2 ? "/" : "") + string(incorrectGuesses > 1 ? "|" : "") + string(incorrectGuesses > 3 ? "\\" : ""),
    " |   " + string(incorrectGuesses > 4 ? "/" : "") + " " + string(incorrectGuesses > 5 ? "\\" : ""),
    " |",
    "_|___"
};


        for (const string& line : figure) {
            cout << line << endl;
        }
    }
};

int main() {
    string secretWord;
    int maxIncorrectGuesses = 6;
    int incorrectGuesses = 0;

    cout << "Enter the secret word: ";
    cin >> secretWord;
    HangmanWord gameWord(secretWord);
    HangmanFigure hangmanFigure;

    while (incorrectGuesses < maxIncorrectGuesses) {
        cout << "Word: " << gameWord.getGuessedWord() << endl;
        char guess;
        cout << "Guess a letter: ";
        cin >> guess;

        if (!gameWord.guess(guess)) {
            ++incorrectGuesses;
            cout << "Incorrect guess. You have " << maxIncorrectGuesses - incorrectGuesses << " tries left." << endl;
            hangmanFigure.draw(incorrectGuesses);
        }

        if (gameWord.isWordGuessed()) {
            cout << "Congratulations! You guessed the word: " << secretWord << endl;
            break;
        }
    }

    if (incorrectGuesses == maxIncorrectGuesses) {
        cout << "You've run out of attempts. The word was: " << secretWord << endl;
        hangmanFigure.draw(incorrectGuesses);
    }

    return 0;
}
