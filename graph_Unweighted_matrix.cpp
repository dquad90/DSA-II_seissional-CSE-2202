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
             graph[i][j] = INT_MAX;
        }
    }
    cout << "Enter edges as pairs of :\n";
    for (int i = 0; i < edges; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w;
    }
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

