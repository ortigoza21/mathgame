 #include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Base class for the MathGame
class MathGame {
protected:
    int score;

public:
    MathGame() : score(0) {}

    virtual void generateQuestion() = 0; // Pure virtual function to enforce polymorphism

    void askQuestion() {
        generateQuestion();
        int answer;
        cout << "Your answer: ";
        cin >> answer;

        if (checkAnswer(answer)) {
            cout << "Correct!" << endl;
            score++;
        } else {
            cout << "Incorrect. Better luck next time!" << endl;
        }
    }

    virtual bool checkAnswer(int answer) = 0; // Pure virtual function for checking the answer

    void showScore() {
        cout << "Your score is: " << score << endl;
    }
};

// Derived class for Addition game
class AdditionGame : public MathGame {
private:
    int num1, num2;

public:
    void generateQuestion() override {
        // Generate two random numbers for addition
        num1 = rand() % 100 + 1;
        num2 = rand() % 100 + 1;

        cout << "What is " << num1 << " + " << num2 << "?" << endl;
    }

    bool checkAnswer(int answer) override {
        return answer == (num1 + num2);
    }
};

// Derived class for Multiplication game
class MultiplicationGame : public MathGame {
private:
    int num1, num2;

public:
    void generateQuestion() override {
        // Generate two random numbers for multiplication
        num1 = rand() % 10 + 1;
        num2 = rand() % 10 + 1;

        cout << "What is " << num1 << " * " << num2 << "?" << endl;
    }

    bool checkAnswer(int answer) override {
        return answer == (num1 * num2);
    }
};

// Function to play the game
void playGame(MathGame* game) {
    char playAgain;
    do {
        game->askQuestion();
        game->showScore();
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed for random number generation

    int choice;
    cout << "Welcome to the Math Game!" << endl;
    cout << "Choose the type of game:" << endl;
    cout << "1. Addition Game" << endl;
    cout << "2. Multiplication Game" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    MathGame* game = nullptr;

    if (choice == 1) {
        game = new AdditionGame(); // Create an addition game
    } else if (choice == 2) {
        game = new MultiplicationGame(); // Create a multiplication game
    } else {
        cout << "Invalid choice. Exiting game." << endl;
        return 0;
    }

    playGame(game);

    delete game; // Clean up the allocated memory
    return 0;
}