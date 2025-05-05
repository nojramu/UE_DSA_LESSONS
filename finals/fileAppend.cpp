#include <iostream>
#include <fstream>
using namespace std;

int main() {
    // Open the file "output.txt" in append mode
    ofstream myfile("output.txt", ios::app); 
    if (myfile.is_open()) {
        // Write a line to the file
        myfile << "This line is added later.\n";
        // Close the file
        myfile.close();
    } else {
        // Print an error message if the file cannot be opened
        cout << "Unable to open file.\n";
    }
    return 0;
}