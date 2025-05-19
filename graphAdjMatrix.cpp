#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Edge {
    char from, to;
    int weight;
};

int main() {
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

    // Collect unique vertices
    map<char, int> vertexIndex;
    int idx = 0;
    for (const auto& edge : edgeList) {
        if (vertexIndex.find(edge.from) == vertexIndex.end())
            vertexIndex[edge.from] = idx++;
        if (vertexIndex.find(edge.to) == vertexIndex.end())
            vertexIndex[edge.to] = idx++;
    }

    int n = vertexIndex.size();
    vector<vector<int>> adjMatrix(n, vector<int>(n, 0));

    // Fill adjacency matrix (directed)
    for (const auto& edge : edgeList) {
        int u = vertexIndex[edge.from];
        int v = vertexIndex[edge.to];
        adjMatrix[u][v] = edge.weight;
    }

    // Print header
    vector<char> vertices(n);
    for (const auto& p : vertexIndex)
        vertices[p.second] = p.first;

    cout << "  ";
    for (char v : vertices) cout << v << " ";
    cout << endl;

    for (int i = 0; i < n; ++i) {
        cout << vertices[i] << " ";
        for (int j = 0; j < n; ++j) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
