#include <iostream>
using namespace std;

string food = "Pizza";
string foodPtr = &food;

int main(){
    cout << "Food: " << food << endl;
    cout << foodPtr << endl;
    cout << &food << endl;
    cout << &foodPtr << endl;
}
