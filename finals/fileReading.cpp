#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // Open the file "output.txt" for reading
    ifstream myfile("output.txt"); // File to read
    string line;
    
    // Check if the file is successfully opened
    if (myfile.is_open()) {
        // Read the file line by line and print each line to the console
        while (getline(myfile, line)) {
            cout << line << endl;
        }
        // Close the file after reading
        myfile.close();
    } else {
        // Print an error message if the file cannot be opened
        cout << "Unable to open file.\n";
    }
    return 0;
}