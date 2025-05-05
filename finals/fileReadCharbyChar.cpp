#include <iostream>
#include <fstream>
using namespace std;

int main() {
    // Open the file "output.txt" for reading
    ifstream file("output.txt");
    char ch;

    // Read the file character by character and print each character to the console
    while (file.get(ch)) {
        cout << ch;
    }

    // Close the file after reading
    file.close();
    return 0;
}