#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Define an Edge as a pair of vertices with a weight
struct Edge {
    char src, dest;
    int weight;
};

int main() {
    // Vertices: a, b, c, d, e
    vector<char> vertices = {'a', 'b', 'c', 'd', 'e'};

    vector<Edge> edgeList = {
        {'a', 'b', 7},
        {'a', 'c', 12},
        {'b', 'd', 5},
        {'c', 'd', 8},
        {'c', 'e', 15},
        {'d', 'e', 3},
        {'e', 'a', 10},
        {'b', 'e', 9},
        {'d', 'a', 6}
    };

    cout << "Edge List Representation of the Graph (with weights):\n";
    for (const auto& edge : edgeList) {
        cout << "(" << edge.src << "," << edge.dest << "," << edge.weight << ")";
        if (&edge != &edgeList.back()) cout << ", " << endl;
    }
    cout << endl;

    return 0;
}