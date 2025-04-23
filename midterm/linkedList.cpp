#include <iostream>
using namespace std;

int main() {
    // Define a linked list node
    struct Node {
        int data;
        Node* next;
    };

    // Create nodes
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;
    head = new Node();
    second = new Node();
    third = new Node();

    head->data = 1; // Assign data in first node
    head->next = third; // Link first node with second
    third->data = 3; // Assign data to third node
    third->next = second; // End of list
    second->data = 2; // Assign data to second node
    second->next = NULL; // Link second node with third
   

    // Print the linked list
    Node* current = head;

    cout << "Linked List: ";
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    return 0;
}