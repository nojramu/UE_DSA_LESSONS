#include <iostream>
using namespace std;

enum Day{sunday, monday, tuesday, wednesday, thursday, friday, saturday};
typedef string str;
typedef unsigned int tralalelo;

int main(){
    tralalelo i = 127;
    cout << i << endl;
    str input;
    cout << "Enter day today: " << endl;
    cin >> input;

    if (input == "sunday") {
        Day today = sunday;
        cout << "Value of today: " << today << endl;
        cout << "Today is Sunday" << endl;
    } else if (input == "monday") {
        Day today = monday;
        cout << "Value of today: " << today << endl;
        cout << "Today is Monday" << endl;
    } else if (input == "tuesday") {
        Day today = tuesday;
        cout << "Value of today: " << today << endl;
        cout << "Today is Tuesday" << endl;
    } else if (input == "wednesday") {
        Day today = wednesday;
        cout << "Value of today: " << today << endl;
        cout << "Today is Wednesday" << endl;
    } else if (input == "thursday") {
        Day today = thursday;
        cout << "Today is Thursday" << endl;
    } else if (input == "friday") {
        Day today = friday;
        cout << "Value of today: " << today << endl;
        cout << "Today is Friday" << endl;
    } else if (input == "saturday") {
        Day today = saturday;
        cout << "Value of today: " << today << endl;
        cout << "Today is Saturday" << endl;
    } else {
        cout << "Invalid input" << endl;
    }
    return 0;
}