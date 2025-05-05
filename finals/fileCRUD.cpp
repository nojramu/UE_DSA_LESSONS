#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void createFile(const string& filename, const string& content) {
    ofstream file(filename);
    if (file) {
        file << content;
        cout << "File created successfully.\n";
    } else {
        cerr << "Error creating file.\n";
    }
}

void readFile(const string& filename) {
    ifstream file(filename);
    if (file) {
        string line;
        while (getline(file, line)) {
            cout << line << '\n';
        }
    } else {
        cerr << "Error reading file.\n";
    }
}

void updateFile(const string& filename, const string& newContent) {
    ofstream file(filename, ios::trunc);
    if (file) {
        file << newContent;
        cout << "File updated successfully.\n";
    } else {
        cerr << "Error updating file.\n";
    }
}

void deleteFile(const string& filename) {
    if (remove(filename.c_str()) == 0) {
        cout << "File deleted successfully.\n";
    } else {
        cerr << "Error deleting file.\n";
    }
}

void displayMenu() {
    cout << "\n1. Create File\n"
         << "2. Read File\n"
         << "3. Update File\n"
         << "4. Delete File\n"
         << "5. Exit\n"
         << "Enter choice: ";
}

void handleChoice(int choice) {
    string filename, content;

    switch (choice) {
        case 1:
            cout << "Enter filename: ";
            cin >> filename;
            cin.ignore();
            cout << "Enter content: ";
            getline(cin, content);
            createFile(filename, content);
            break;
        case 2:
            cout << "Enter filename: ";
            cin >> filename;
            readFile(filename);
            break;
        case 3:
            cout << "Enter filename: ";
            cin >> filename;
            cin.ignore();
            cout << "Enter new content: ";
            getline(cin, content);
            updateFile(filename, content);
            break;
        case 4:
            cout << "Enter filename: ";
            cin >> filename;
            deleteFile(filename);
            break;
        case 5:
            cout << "Exiting program.\n";
            exit(0);
        default:
            cout << "Invalid choice. Please try again.\n";
    }
}

int main() {
    int choice;

    while (true) {
        displayMenu();
        cin >> choice;
        handleChoice(choice);
    }

    return 0;
}
