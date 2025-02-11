#include <iostream>

using namespace std;

int main() {
    const int SIZE = 10;
    int arr[SIZE];
    int searchElement, index = -1;

    // Input 10 elements into the array
    cout << "Enter 10 elements for the array:" << endl;
    for (int i = 0; i < SIZE; ++i) {
        cin >> arr[i];
    }

    // Input the element to search for
    cout << "Enter the element to search for: ";
    cin >> searchElement;

    // Search for the element in the array
    for (int i = 0; i < SIZE; ++i) {
        if (arr[i] == searchElement) {
            index = i;
            break;
        }
    }

    // Output the index of the element if found
    if (index != -1) {
        cout << "Element found at index: " << index << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}