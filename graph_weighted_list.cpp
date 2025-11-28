#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
    int vertices, edges;
    cout << "Enter number of vertices: ";
    cin >> vertices;
    cout << "Enter number of edges: ";
    cin >> edges;
    vector<vector<pair<int, int>>> List(vertices);
    cout << "Enter (u v w):\n";
    for (int i = 0; i < edges; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        List[u].push_back({v, w});
        List[v].push_back({u, w});
    }
    for (int i = 0; i < List.size(); ++i) {
        cout << i << " -> ";
        for (int j = 0; j < List[i].size(); ++j) {
    cout << "(" << List[i][j].first << "," << List[i][j].second << ") ";
}
        cout << endl;
    }
    return 0;
}