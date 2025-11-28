#include <bits/stdc++.h>
using namespace std;
int main() {
    int vertices, edges;
    cout << "Enter number of vertices: ";
    cin >> vertices;
    cout << "Enter number of edges: ";
    cin >> edges;
    vector<vector<pair<int, int>>> adj(vertices);

    cout << "Enter edges as (u v w): " << endl;
    for (int i = 0; i < edges; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w)); 
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, 
    greater<pair<int, int>>> pq;
    vector<int> visited(vertices, 0);
    vector<int> parent(vertices, -1);
    vector<int> key(vertices, 1e9);
    int start = 0; 
    key[start] = 0;
    pq.push(make_pair(0, start));
    int mst_cost = 0;
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = 1;
        mst_cost += key[u];
        for (int i = 0; i < adj[u].size(); ++i) {
            int v = adj[u][i].first;
            int weight = adj[u][i].second;

            if (!visited[v] && weight < key[v]) {
                key[v] = weight;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }
    cout << "\nMinimum Spanning Tree edges:\n";
    for (int i = 1; i < vertices; ++i) {
        cout << parent[i] << " - " << i << " (weight: " << key[i] << ")\n";
    }
    cout << "Total cost of MST: " << mst_cost << endl;
    return 0;
}

