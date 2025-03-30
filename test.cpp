#include <iostream>
using namespace std;

int a = 20;
int b = 10;
int c = 15;
char letter = 'c';

int main() {
    int i = 0;
    do {
        cout << "LOW" << endl;
        i++;
        for(int j = 0; j < 3; j++) {
            cout << "MEDIUM" << endl;
        }
    } while (i < 10);

    return 0;

}