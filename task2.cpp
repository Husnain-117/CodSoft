#include <iostream>
#include <stdexcept>
#include <chrono>
#include <thread>

using namespace std;

template <typename T>

T performOperation(T num1, T num2, char operation)
{
    switch (operation)
    {
    case '+':
        return num1 + num2;
    case '-':
        return num1 - num2;
    case '*':
        return num1 * num2;
    case '/':
        if (num2 != 0)
        {
            return num1 / num2;
        }
        else
        {
            throw invalid_argument("Error: Division by zero is not allowed.");
        }
    default:
        throw invalid_argument("Error: Invalid operation.");
    }
}

int main()
{
    char choice;
    do
    {
        float num1, num2, result;
        char operation;

        cout << "Enter first number: ";
        while (!(cin >> num1))
        {

            cout << "Invalid input. Enter a valid number: ";
        }

        cout << "Enter second number: ";
        while (!(cin >> num2))
        {

            cout << "Invalid input. Enter a valid number: ";
        }

        cout << "Enter operation (+, -, *, /): ";
        while (!(cin >> operation) || (operation != '+' && operation != '-' && operation != '*' && operation != '/'))
        {

            cout << "Invalid input. Enter a valid operation (+, -, *, /): ";
        }

        try
        {
            result = performOperation(num1, num2, operation);
            cout << "Result: " << result << endl;
        }
        catch (const invalid_argument &e)
        {
            cerr << e.what() << endl;
        }

        cout << "Do you want to perform another calculation? (y/n): ";
        cin >> choice;

       
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
