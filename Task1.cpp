#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

void GuessNumber(int lower, int upper)
{
    int count = 1;

    // Seed the random number generator with the current time
    srand(time(0));

    // Stores a random number in a variable within the specified range
    int g = rand() % (upper - lower + 1) + lower;

    cout << "I will generate a random number between " << lower << " and " << upper << ". Can you guess it?" << endl;
    cout << "Hints will be provided after each incorrect guess." << endl << endl;

    int x;
    cout << "Guess the number: ";
    cin >> x;

    while (x != g)
    {
        // checkouts
        if (x < 0)
        {
            cout << "Invalid input! Please enter a non-negative number: ";
        }
        else if (x < lower || x > upper)
        {
            cout << "Out of range! Please enter a number between " << lower << " and " << upper << ": ";
        }
        else
        {
            cout << "Incorrect guess! Try again." << endl;

            // Add condition to give hints
            if (x < g)
            {
                cout << "HINT: Your number is less than the actual number." << endl;
            }
            else
            {
                cout << "HINT: Your number is greater than the actual number." << endl;
            }
        }

        // Get a new guess from the user
        cout << "Guess the number: ";
        cin >> x;
        count++;
    }


    cout << endl << "Congratulations, " << "You guessed the number in " << count << " attempts!" << endl << endl;
}



int main()
{
    string playerName;
    cout << "Enter your name: ";
    getline(cin, playerName);

    int lower, upper;
    char playAgain;

    do
    {
        cout << "Welcome, " << playerName << "!" << endl;
        cout << "Enter the range for the number (lower and upper bounds, separated by a space): ";
        cin >> lower >> upper;

        while (lower > upper || lower < 0 || upper < 0)
        {
            cout << "Invalid range! Please enter a valid range (lower and upper bounds): ";
            cin >> lower >> upper;
        }

        GuessNumber(lower, upper);

        // Ask if the user wants to play again
        cout << "Do you want to play again? (Y/N): ";
        cin >> playAgain;

       

    } while (playAgain == 'Y' || playAgain == 'y');

    cout << "Thanks for playing the Number Guessing Game! Goodbye, " << playerName << "!" << endl;

    return 0;
}
