#include<iostream>
using namespace std;

double divide (int a = 10, double b = 2) {
    return a/b;

}

int main () {
    int a= 9 ;
    int  b= 30- 3;
    cout << divide() << endl;
    cout << divide(14) << endl;
    cout << divide(10,3) << endl;
    cout << divide(a) << endl;
    cout << divide(a, a+ b) << endl;
    //system("pause");
}
