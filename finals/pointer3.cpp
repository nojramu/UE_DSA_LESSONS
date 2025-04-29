#include <iostream>
using namespace std;

typedef int integers;
typedef unsigned int uint;
typedef char* pchar;

int main(){
    uint andy = 6;
    uint * ted = &andy;
    cout << "andy: " << &andy << endl;
    cout << "ted: " << ted << endl;
    cout << "andy: " << *ted << endl;
}