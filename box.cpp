#include <iostream>

using namespace std;

void printBox(int width, int height) {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            cout << "*";
        }
        cout << endl;
    }
}

int main() {
    int width = 10;
    int height = 5;

    printBox(width, height);

    return 0;
}