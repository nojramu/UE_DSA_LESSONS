#include <iostream>
#include <fstream>
using namespace std;

int main() {
    // Open the file "output.txt" for reading
    ifstream fin("output.txt");
    char ch; // Variable to store each character read from the file
    int count = 0; // Counter to keep track of the number of characters

    // Read the file character by character, including whitespace
    while (fin >> noskipws >> ch) { // noskipws ensures whitespace is not skipped
        count++; // Increment the character count
    }

    // Output the total character count
    cout << "Character count: " << count << endl;

    // Close the file
    fin.close();
    return 0;
}