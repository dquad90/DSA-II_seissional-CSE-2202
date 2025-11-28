#include <bits/stdc++.h>
using namespace std;
int main() {
    int vertices, edges;
    cout << "Enter number of vertices: ";
    cin >> vertices;
    cout << "Enter number of edges: ";
    cin >> edges;
    vector<vector<int>> adj(vertices);

    cout << "Enter edges as pairs (u v):\n";
    for (int i = 0; i < edges; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int root;
    cout << "Enter vertex for BFS: ";
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

        // visit all adjacent vertices
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
    return 0;
}






// vector<bool> visited(vertices, false);
// stack<int> s;

// visited[root] = true;
// s.push(root);

// cout << "DFS traversal order: ";
// while (!s.empty()) {
//     int node = s.top();
//     s.pop();
//     cout << node << " ";

//     // push unvisited neighbors
//     for (int neighbor : adj[node]) {
//         if (!visited[neighbor]) {
//             visited[neighbor] = true;
//             s.push(neighbor);
//         }
//     }
// }
