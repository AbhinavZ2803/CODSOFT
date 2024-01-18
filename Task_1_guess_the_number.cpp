#include <iostream>
#include <cstdlib>
#include <ctime>

class GuessMaster {
private:
    int secretNumber;
    int playerGuess;
    int attempts;

public:
    GuessMaster() {
        srand(static_cast<unsigned int>(time(0)));  
        secretNumber = rand() % 100 + 1;  
        attempts = 0;
    }

    void welcomeMessage() {
        std::cout << "Welcome to the GuessMaster Game!\n";
        std::cout << "I am the GuessMaster, and I have selected a secret number between 1 and 100.\n";
        std::cout << "Your task is to guess the number. Let's see how many attempts you need!\n";
    }

    void getPlayerGuess() {
        std::cout << "Enter your guess: ";
        std::cin >> playerGuess;
        attempts++;
    }

    void evaluateGuess() {
        if (playerGuess == secretNumber) {
            std::cout << "Congratulations! You've guessed the correct number in " << attempts << " attempts.\n";
        } else if (playerGuess < secretNumber) {
            std::cout << "Too low! Try again.\n";
        } else {
            std::cout << "Too high! Try again.\n";
        }
    }
};

int main() {
    GuessMaster game;
    game.welcomeMessage();

    while (true) {
        game.getPlayerGuess();
        game.evaluateGuess();

        std::cout << "---------------------------\n";

     
        char playAgain;
        std::cout << "Do you want to play again? (y/n): ";
        std::cin >> playAgain;

        if (playAgain != 'y' && playAgain != 'Y') {
            std::cout << "Thank you for playing GuessMaster! Goodbye!\n";
            break;
        } else {
          
            game = GuessMaster();
            game.welcomeMessage();
        }
    }

    return 0;
}
