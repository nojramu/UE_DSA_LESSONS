#include <iostream>
using namespace std;

int main() {
    int seats[10] = {0}; // 0 means available, 1 means booked
    int seatNumber;
    char choice;

    do {
        cout << "\nAvailable seats (0 = available, 1 = booked):\n";
        for (int i = 0; i < 10; i++) {
            cout << "Seat " << i << ": " << seats[i] << "  ";
        }

        cout << "\nEnter seat number to book (0-9): ";
        cin >> seatNumber;

        if (seatNumber < 0 || seatNumber >= 10) {
            cout << "Invalid seat number! Please enter a number between 0 and 9.\n";
        } else if (seats[seatNumber] == 0) {
            seats[seatNumber] = 1;
            cout << "Seat " << seatNumber << " booked successfully!\n";
        } else {
            cout << "Seat " << seatNumber << " is already booked. Please choose another seat.\n";
        }

        cout << "Book another seat? (y/n): ";
        cin >> choice;

    } while (tolower(choice) == 'y');

    cout << "Thank you for using our booking system!\n";
    return 0;
}