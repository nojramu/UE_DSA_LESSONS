#include <iostream>
using namespace std;

struct Age{
    int age;
};

int main(){
    Age a;
    a.age = 25;
    cout << "Age: " << a.age << endl;
    return 0;
}