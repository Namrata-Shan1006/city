// tourism_dijkstra.cpp
// Smart Tourism Planner using Dijkstra's Algorithm
// C++17 compatible

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

// Graph using adjacency list
// pair<neighbor, distance>
class Graph {
    int V;
    vector<vector<pair<int,int>>> adj;

public:
    Graph(int v) {
        V = v;
        adj.resize(V);
    }

    // Add road (undirected)
    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // Dijkstra algorithm
    vector<int> dijkstra(int src) {
        vector<int> dist(V, INF);
        dist[src] = 0;

        // Min heap {distance, node}
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        pq.push({0, src});

        while (!pq.empty()) {
            int curDist = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            // Ignore outdated entry
            if (curDist > dist[u]) continue;

            // Explore neighbors
            for (auto &edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Number of tourist locations
    int V = 5;
    Graph g(V);

    // Dataset edges (same as CSV)
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 1);
    g.addEdge(2, 1, 2);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 3, 5);
    g.addEdge(3, 4, 3);
    g.addEdge(1, 4, 7);

    int source = 0;
    vector<int> dist = g.dijkstra(source);

    cout << "Shortest distances from Tourist Start Point (" 
         << source << "):\n";

    for (int i = 0; i < V; i++) {
        cout << "To location " << i << " = ";
        if (dist[i] == INF)
            cout << "Not reachable\n";
        else
            cout << dist[i] << " km\n";
    }

    return 0;
}

