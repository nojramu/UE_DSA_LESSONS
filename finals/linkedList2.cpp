#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;
    Node* fourth = NULL;

    head = new Node();
    second = new Node();
    third = new Node();
    fourth = new Node();

    head->data = 1;
    head->next = third;
    third->data = 3;
    third->next = second;
    second->data = 2;
    second->next = fourth;
    fourth->data = 4;
    fourth->next = NULL;

    Node* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    return 0;
}