#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

struct Edge {
    string from;
    string to;
    int weight;
};

int main() {
    // Edge list
    vector<Edge> edgeList = {
        {"a", "b", 7},
        {"a", "c", 12},
        {"b", "d", 5},
        {"c", "d", 8},
        {"c", "e", 15},
        {"d", "e", 3},
        {"e", "a", 10},
        {"b", "e", 9},
        {"d", "a", 6}
    };

    // Build adjacency list from edge list
    unordered_map<string, vector<pair<string, int>>> adjList;
    for (const auto& edge : edgeList) {
        adjList[edge.from].push_back({edge.to, edge.weight});
    }

    // Print adjacency list
    for (const auto& pair : adjList) {
        cout << pair.first << ": ";
        for (const auto& edge : pair.second) {
            cout << "(" << edge.first << ", " << edge.second << ") ";
        }
        cout << endl;
    }

    return 0;
}