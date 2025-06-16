#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;

struct Edge {
    char from, to;
    int weight;
};

unordered_map<char, vector<pair<char, int>>> buildGraph(const vector<Edge>& edgeList) {
    unordered_map<char, vector<pair<char, int>>> graph;
    for (const auto& edge : edgeList) {
        graph[edge.from].emplace_back(edge.to, edge.weight);
        // If undirected, add the reverse edge as well
        // graph[edge.to].emplace_back(edge.from, edge.weight);
    }
    return graph;
}

unordered_map<char, int> dijkstra(
    const unordered_map<char, vector<pair<char, int>>>& graph,
    char start
) {
    unordered_map<char, int> dist;
    for (const auto& node : graph) {
        dist[node.first] = INT_MAX;
    }
    dist[start] = 0;

    using P = pair<int, char>;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.emplace(0, start);

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (const auto& [v, w] : graph.at(u)) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }
    }
    return dist;
}

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

    auto graph = buildGraph(edgeList);

    char start, last;
    cout << "Enter start node: ";
    cin >> start;
    cout << "Enter last node: ";
    cin >> last;

    auto dist = dijkstra(graph, start);

    cout << "Shortest distances from node " << start << ":\n";
    for (const auto& [node, d] : dist) {
        cout << node << ": ";
        if (d == INT_MAX) cout << "INF";
        else cout << d;
        cout << '\n';
    }

    cout << "Shortest distance from " << start << " to " << last << ": ";
    if (dist.count(last) && dist[last] != INT_MAX)
        cout << dist[last] << '\n';
    else
        cout << "No path\n";

    return 0;
}