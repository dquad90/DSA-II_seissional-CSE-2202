#include <bits/stdc++.h>
using namespace std;
int main() {
    int vertices, edges;
    cout << "Enter number of vertices: ";
    cin >> vertices;
    cout << "Enter number of edges: ";
    cin >> edges;
    vector<vector<int>> graph(vertices, vector<int>(vertices, 0));
    cout << "Enter edges (u v):\n";
    for (int i = 0; i < edges; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
    }
    int source;
    cout << "Enter source vertex: ";
    cin >> source;

    vector<int> dist(vertices, INT_MAX);
    queue<int> q;
    dist[source] = 0;
    q.push(source);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < vertices; ++v) {
            if (graph[u][v] && dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    cout << "\nDistance from vertex " << source << ":\n";
    for (int i = 0; i < vertices; ++i) {
        if (dist[i] == INT_MAX)
            cout << "Vertex " << i << ": Unreachable\n";
        else
            cout << "Vertex " << i << ": " << dist[i] << endl;
    }
    return 0;
}
