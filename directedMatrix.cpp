#include <bits/stdc++.h>
using namespace std;

int main() {
    int vertices, edges;
    cout << "Enter number of vertices: ";
    cin >> vertices;
    cout << "Enter number of edges: ";
    cin >> edges;
    vector<vector<int>> graph(vertices, vector<int>(vertices, 0));
    cout << "Enter edges as: u v (edge from u to v)\n";
    for (int i = 0; i < edges; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1; // directed edge u → v
    }
    cout << "\nAdjacency Matrix (Directed, Unweighted Graph):\n";
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
