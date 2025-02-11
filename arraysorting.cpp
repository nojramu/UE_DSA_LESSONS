#include <iostream>

using namespace std;

int main() {
    const int SIZE = 10;
    int arr[SIZE];

    // Input 10 elements into the array
    cout << "Enter 10 elements for the array:" << endl;
    for (int i = 0; i < SIZE; ++i) {
        cin >> arr[i];
    }

    // Bubble sort the array
    for (int i = 0; i < SIZE - 1; ++i) {
        for (int j = 0; j < SIZE - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {//Change the sign to sort in descending order
                // Swap the elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Output the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < SIZE; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
