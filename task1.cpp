#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

// Function to generate a random number within a given range
int generateRandomNumber(int minRange, int maxRange) {
    return rand() % (maxRange - minRange + 1) + minRange;
}

int main() {
    cout << "Welcome to the Number Guessing Game!\n";

    do {
        int minRange, maxRange;
        cout << "Enter the range for the number (minimum and maximum): ";
        cin >> minRange >> maxRange;

        if (minRange >= maxRange || minRange < 1) {
            cout << "Invalid range. Please enter a valid range.\n";
            return 1;
        }

        cout << "Select difficulty level:\n";
        cout << "1. Easy\n";
        cout << "2. Medium\n";
        cout << "3. Hard\n";
        int difficulty;
        cin >> difficulty;

        int maxAttempts;
        switch (difficulty) {
            case 1:
                maxAttempts = 10;
                break;
            case 2:
                maxAttempts = 7;
                break;
            case 3:
                maxAttempts = 5;
                break;
            default:
                cout << "Invalid difficulty level. Defaulting to Medium.\n";
                maxAttempts = 7;
                break;
        }

        cout << "I have selected a number between " << minRange << " and " << maxRange << ". Try to guess it!\n";

        srand(time(NULL)); // Seed the random number generator
        int secretNumber = generateRandomNumber(minRange, maxRange);
        int attempts = 0;
        int guess;

        while (attempts < maxAttempts) {
            cout << "Enter your guess: ";
            if (!(cin >> guess)) {
                cout << "Invalid input. Please enter a valid number.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            attempts++;

            if (guess < secretNumber) {
                cout << "Too low! ";
            } else if (guess > secretNumber) {
                cout << "Too high! ";
            } else {
                cout << "Congratulations! You guessed the number.\n";
                break;
            }
            cout << "Attempts left: " << maxAttempts - attempts << endl;
        }

        if (attempts == maxAttempts) {
            cout << "Sorry, you've run out of attempts. The correct number was " << secretNumber << endl;
        }

        // Calculate score based on difficulty and remaining attempts
        int score = (attempts > 0) ? (maxAttempts * difficulty * (maxAttempts - attempts + 1) / maxAttempts) : 0;

        cout << "Your score: " << score << endl;

        // Ask if the player wants to play again
        char choice;
        cout << "Do you want to play again? (y/n): ";
        cin >> choice;

        if (choice != 'y' && choice != 'Y') {
            cout << "Thank you !" << endl;
            break;
        }

    } while (true);

    return 0;
}