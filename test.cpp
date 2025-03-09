#include <iostream>
using namespace std;

void reverseArray(int arr[], int size) {
    for (int i = 0; i < size / 2; ++i) swap(arr[i], arr[size - 1 - i]);
}

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i)
        for (int j = 0; j < size - 1 - i; ++j)
            if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
}

void printValues(int arr[], int size, bool even) {
    cout << (even ? "Even" : "Odd") << " values: ";
    for (int i = 0; i < size; ++i)
        if ((arr[i] % 2 == 0) == even) cout << arr[i] << " ";
    cout << endl;
}

void printArray(int arr[], int size) {
    cout << "Array: ";
    for (int i = 0; i < size; ++i) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arraySize;
    cout << "Enter the size of the array: ";
    cin >> arraySize;

    if (arraySize <= 0) {
        cout << "Invalid array size. Exiting...\n";
        return 1;
    }

    int* array = new int[arraySize];
    cout << "Enter " << arraySize << " numbers: ";
    for (int i = 0; i < arraySize; ++i) cin >> array[i];

    int choice;
    do {
        cout << "\nChoose an option:\n"
             << "1. Reverse the array\n"
             << "2. Bubble sort the array\n"
             << "3. Print even values\n"
             << "4. Print odd values\n"
             << "5. Exit\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                reverseArray(array, arraySize);
                cout << "Array reversed.\n";
                printArray(array, arraySize);
                break;
            case 2:
                bubbleSort(array, arraySize);
                cout << "Array sorted.\n";
                printArray(array, arraySize);
                break;
            case 3:
                printValues(array, arraySize, true);
                break;
            case 4:
                printValues(array, arraySize, false);
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    delete[] array;
    return 0;
}
