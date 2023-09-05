#include <iostream>
#include <string>
#include <vector>

class HangmanWord {
private:
    std::string secretWord;
    std::string guessedWord;

public:
    HangmanWord(const std::string& word) : secretWord(word) {
        guessedWord = std::string(secretWord.length(), '_');
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

    std::string getGuessedWord() const {
        return guessedWord;
    }
};

class HangmanFigure {
public:
    void draw(int incorrectGuesses) {
        std::vector<std::string> figure = {
    "  ____",
    " |    |",
    " |    " + std::string(incorrectGuesses > 0 ? "O" : ""),
    " |   " + std::string(incorrectGuesses > 2 ? "/" : "") + std::string(incorrectGuesses > 1 ? "|" : "") + std::string(incorrectGuesses > 3 ? "\\" : ""),
    " |   " + std::string(incorrectGuesses > 4 ? "/" : "") + " " + std::string(incorrectGuesses > 5 ? "\\" : ""),
    " |",
    "_|___"
};


        for (const std::string& line : figure) {
            std::cout << line << std::endl;
        }
    }
};

int main() {
    std::string secretWord;
    int maxIncorrectGuesses = 6;
    int incorrectGuesses = 0;

    std::cout << "Enter the secret word: ";
    std::cin >> secretWord;
    HangmanWord gameWord(secretWord);
    HangmanFigure hangmanFigure;

    while (incorrectGuesses < maxIncorrectGuesses) {
        std::cout << "Word: " << gameWord.getGuessedWord() << std::endl;
        char guess;
        std::cout << "Guess a letter: ";
        std::cin >> guess;

        if (!gameWord.guess(guess)) {
            ++incorrectGuesses;
            std::cout << "Incorrect guess. You have " << maxIncorrectGuesses - incorrectGuesses << " tries left." << std::endl;
            hangmanFigure.draw(incorrectGuesses);
        }

        if (gameWord.isWordGuessed()) {
            std::cout << "Congratulations! You guessed the word: " << secretWord << std::endl;
            break;
        }
    }

    if (incorrectGuesses == maxIncorrectGuesses) {
        std::cout << "You've run out of attempts. The word was: " << secretWord << std::endl;
        hangmanFigure.draw(incorrectGuesses);
    }

    return 0;
}
