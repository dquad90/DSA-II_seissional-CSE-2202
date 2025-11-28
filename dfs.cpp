#include <bits/stdc++.h>
using namespace std;

int main() {
    int vertices, edges;
    cout << "Enter  vertices: ";
    cin >> vertices;
    cout << "Enter  edges: ";
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
    cout << "Enter root: ";
    cin >> root;
    vector<bool> visited(vertices, false);
    stack<int> s;
    visited[root] = true;
    s.push(root);
    cout << "DFS traversal order: ";
    while (!s.empty()) {
        int node = s.top();
        s.pop();
        cout << node << " ";
        for (int i = 0; i < vertices; ++i) {
            if (graph[node][i] == 1 && !visited[i]) {
                visited[i] = true;
                s.push(i);
            }
        }
    }
    cout << endl;
    return 0;
}