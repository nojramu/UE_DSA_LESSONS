#include <iostream>
#include <fstream>
using namespace std;

int main() {
    // Create an output file stream object and open "output.txt" for writing
    ofstream myfile("output.txt"); // Creates or overwrites "output.txt"
    
    // Check if the file is successfully opened
    if (myfile.is_open()) {
        // Write lines of text to the file
        myfile << "This is a sample line.\n";
        myfile << "Another line of text.\n";
        
        // Close the file to ensure data is saved and resources are released
        myfile.close(); // Important to close the file
    } else {
        // Print an error message if the file could not be opened
        cout << "Unable to open file.\n";
    }
    return 0; // Indicate successful program termination
}