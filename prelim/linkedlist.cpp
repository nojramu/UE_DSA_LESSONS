#include <iostream>
using namespace std;

struct Song {
    string title;
    Song* next;
};

void printPlaylist(Song* head) {
    Song* temp = head;
    while (temp != nullptr) {
        cout << temp->title << " -> ";
        temp = temp->next;
    }
    cout << "END\n";
}

int main() {
    Song* song1 = new Song{"Song A", nullptr};
    Song* song2 = new Song{"Song B", nullptr};
    Song* song3 = new Song{"Song C", nullptr};

    song1->next = song2;
    song2->next = song3;

    printPlaylist(song1);

    return 0;
}