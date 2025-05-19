#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>

using namespace std;

struct Edge {
    char from;
    char to;
};

class Graph {
public:
    unordered_map<char, vector<char>> adj;

    void addEdge(char u, char v) {
        adj[u].push_back(v);
    }

    void dfs(char node, unordered_set<char>& visited) {
        if (visited.count(node)) return;
        cout << node << " ";
        visited.insert(node);
        for (auto& neighbor : adj[node]) {
            dfs(neighbor, visited);
        }
    }
};

int main() {
    vector<Edge> edgeList = {
        {'a', 'b'},
        {'a', 'c'},
        {'b', 'd'},
        {'c', 'd'},
        {'c', 'e'},
        {'d', 'e'},
        {'e', 'a'},
        {'b', 'e'},
        {'d', 'a'}
    };

    Graph g;
    for (const auto& edge : edgeList) {
        g.addEdge(edge.from, edge.to);
    }

    unordered_set<char> visited;
    g.dfs('a', visited);
    cout << endl;
    return 0;
}
