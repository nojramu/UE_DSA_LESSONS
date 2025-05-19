#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <set>

using namespace std;

struct Edge {
    char u, v;
};

class Graph {
public:
    unordered_map<char, vector<char>> adj;

    void addEdge(char u, char v) {
        adj[u].push_back(v);
    }

    void bfs(char start) {
        set<char> visited;
        queue<char> q;

        visited.insert(start);
        q.push(start);

        while (!q.empty()) {
            char node = q.front();
            q.pop();
            cout << node << " ";

            for (char next : adj[node]) {
                if (visited.find(next) == visited.end()) {
                    visited.insert(next);
                    q.push(next);
                }
            }
        }
        cout << endl;
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
        g.addEdge(edge.u, edge.v);
    }

    cout << "BFS starting from node 'a': ";
    g.bfs('a');

    return 0;
}
