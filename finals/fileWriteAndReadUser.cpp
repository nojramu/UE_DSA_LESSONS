#include <iostream>
#include <fstream>
using namespace std;

int main() {
    char name[50]; // Array to store the user's name
    int age;       // Variable to store the user's age

    // Create and open a file for writing
    ofstream outfile("user.txt");
    cout << "Enter your name: ";
    cin.getline(name, 50); // Read the user's name
    cout << "Enter your age: ";
    cin >> age;            // Read the user's age

    // Write the user's name and age to the file
    outfile << name << endl << age << endl;
    outfile.close(); // Close the output file

    // Open the file for reading
    ifstream infile("user.txt");
    infile.getline(name, 50); // Read the name from the file
    infile >> age;            // Read the age from the file
    infile.close(); // Close the input file

    // Display the name and age read from the file
    cout << "Name: " << name << ", Age: " << age << endl;
    return 0;
}