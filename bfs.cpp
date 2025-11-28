#include <bits/stdc++.h>
using namespace std;

int main() {
    int vertices, edges;
    cout << "Enter number of vertices: ";
    cin >> vertices;
    cout << "Enter number of edges: ";
    cin >> edges;
    int graph[vertices][vertices];
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            graph[i][j] = 0;
        }
    }
    cout << "Enter edges as pairs (u v):\n";
    for (int i = 0; i < edges; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    int root;
    cout << "Enter  vertex for BFS: ";
    cin >> root;
    vector<bool> visited(vertices, false);
    queue<int> q;
    visited[root] = true;
    q.push(root);
    cout << "BFS traversal order: ";
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int i = 0; i < vertices; ++i) {
            if (graph[node][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    cout << endl;
    return 0;
}
