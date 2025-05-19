#include <iostream>
using namespace std;

string name = "Moalla";
string *namePtr = &name;

int main() {
    cout << name << endl;
    cout << &name << endl;
    cout << *namePtr << endl;
    cout << &namePtr << endl;
}
