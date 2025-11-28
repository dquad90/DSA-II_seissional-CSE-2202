#include <bits/stdc++.h>
using namespace std;

// BFS to find shortest path distances from start
vector<int> bfs_distance(const vector<vector<int>>& adjList, int start) {
    int n = adjList.size();
    vector<int> dist(n, -1); // -1 means unreachable
    queue<int> q;

    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adjList[u]) { // iterate over neighbors
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    return dist;
}

int main() {
    int vertices, edges;
    cout << "Enter number of vertices: ";
    cin >> vertices;
    cout << "Enter number of edges: ";
    cin >> edges;

    vector<vector<int>> adjList(vertices);
    cout << "Enter edges (u v):\n";
    for (int i = 0; i < edges; ++i) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v); // directed edge
    }

    int start;
    cout << "Enter starting vertex for BFS: ";
    cin >> start;

    vector<int> distances = bfs_distance(adjList, start);

    cout << "\nShortest distances from vertex " << start << ":\n";
    for (int i = 0; i < vertices; ++i) {
        if (distances[i] == -1)
            cout << "Vertex " << i << ": Unreachable\n";
        else
            cout << "Vertex " << i << ": " << distances[i] << endl;
    }

    return 0;
}
