#include <iostream>
using namespace std;

struct Student {
    string name;
};

int main(){
    Student s1={"Jolo"};
    cout << s1.name << endl;
    return 0;
}