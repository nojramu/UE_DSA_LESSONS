#include<iostream>
using namespace std;

int sum (); // FUNCTION DECLARATION
int diff ();
int product ();
void print();

int main () {
    char choice;
    do { 
        print();
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 'A': {
                cout << "You chose sum." << endl;
                int total = sum();
                cout << "The sum of num3 and num4 = " << total << endl;
                break;
            }
            case 'B': {
                cout << "You chose difference." << endl;
                int result = diff();
                cout << "The difference of num1 to num2 = " << result << endl;
                break;
            }
            case 'C': {
                cout << "You chose product." << endl;
                int tota = product();
                cout << "The product of the two numbers is = " << tota << endl;
                break;
            }
            case 'D': cout << "You chose to quit." << endl; break;
            default: cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 'D' );
    
    int total, result, tota;
    result = diff();
    total = sum();
    tota = product();

    cout << "The difference of num1 to num2 =" <<result << endl;
    cout << "The sum of num3 and num4 =" <<total << endl;  
    cout << "The product of the two numbers is  =" << tota << endl;

    //system("pause"); 
}

int diff () {
    int num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    return num1 - num2;
    }

int sum () { // FUNCTION DEFINITION
    int num3, num4;
    cout << "Enter two numbers: ";
    cin >> num3 >> num4;
    return num3 + num4;
    }
    
int product () {
    int num5, num6;
    cout << "Enter two numbers: ";
    cin >> num5 >> num6;
    return num5 * num6;
    }

void print () {
    cout << "[A] Sum" << endl;
    cout << "[B] Difference" << endl;
    cout << "[C] Product" << endl;
    cout << "[D] Quit" << endl;
    }