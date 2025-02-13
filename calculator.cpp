#include <iostream>
using namespace std;
#include <limits>

// Function declarations
double add(double a, double b) { return a + b; }
double subtract(double a, double b) { return a - b; }
double multiply(double a, double b) { return a * b; }
double divide(double a, double b) {
    if (b == 0) {
        cout << "Error: Division by zero!" << endl;
        return 0;
    }
    return a / b;
}

int main() {
    char operation;
    double num1, num2, result;
    
    cout << "Enter first number: ";
    while (!(cin >> num1)) {
        cout << "Invalid input. Please enter a number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    while (true) {
        cout << "Enter operation (+, -, *, /) or 'q' to quit: ";
        cin >> operation;
        while (operation != '+' && operation != '-' && operation != '*' && operation != '/' && operation != 'q') {
            cout << "Invalid operation. Please enter a valid operation (+, -, *, /) or 'q' to quit: ";
            cin >> operation;
        }

        // Check for exit condition
        if (operation == 'q') {
            cout << "Exiting calculator. Goodbye!" << endl;
            break;
        }

        cout << "Enter next number: ";
        while (!(cin >> num2)) {
            cout << "Invalid input. Please enter a number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        // Performing the operation
        switch (operation) {
            case '+': result = add(num1, num2); break;
            case '-': result = subtract(num1, num2); break;
            case '*': result = multiply(num1, num2); break;
            case '/': result = divide(num1, num2); break;
            default: 
                cout << "Invalid operation! Try again." << endl;
                continue;
        }

        // Display the result
        cout << "Result: " << result << endl;

        // Update num1 for the next iteration
        num1 = result;
    }

    return 0;
}