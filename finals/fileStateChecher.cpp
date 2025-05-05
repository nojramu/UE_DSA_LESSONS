#include <iostream>
#include <fstream>
using namespace std;

int main() {
    // Attempt to open a file named "nonexistent.txt"
    ifstream file("nonexistent.txt");
    
    // Check if the file could not be opened
    if (!file) {
        cout << "File could not be opened.\n";
    }

    // Check if the fail flag is set (indicates a logical error or format error)
    if (file.fail()) {
        cout << "Fail flag is true (bad or format error).\n";
    }

    // Check if the bad flag is set (indicates a fatal I/O error)
    if (file.bad()) {
        cout << "Bad flag is true (fatal I/O error).\n";
    }

    // Check if the end-of-file (EOF) flag is set
    if (file.eof()) {
        cout << "End of file reached.\n";
    }

    // Clear all state flags to reset the stream
    file.clear(); // Reset state flags
    file.close(); // Close the file
    return 0;
}