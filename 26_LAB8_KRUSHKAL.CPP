#include <bits/stdc++.h>
using namespace std;
int findParent(int node, int parent[]) {
    if (parent[node] == node)
        return node;
    parent[node] = findParent(parent[node], parent);
    return parent[node];
}
void unionSets(int a, int b, int parent[], int sizeArr[]) {
    a = findParent(a, parent);
    b = findParent(b, parent);
    if (a != b) {
        if (sizeArr[a] < sizeArr[b]) {
            int temp = a;
            a = b;
            b = temp;
        }
        parent[b] = a;
        sizeArr[a] += sizeArr[b];
    }
}
int main() {
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;
    struct Edge {
        int u, v, w;
    };
    vector<Edge> edges(m);
    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.w < b.w;
    });

    int parent[1000], sizeArr[1000];
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        sizeArr[i] = 1;
    }
    int totalWeight = 0;
    vector<Edge> mst;
    for (int i = 0; i < m; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;
        int pu = findParent(u, parent);
        int pv = findParent(v, parent);
        if (pu != pv) {
            mst.push_back(edges[i]);
            totalWeight += w;
            unionSets(u, v, parent, sizeArr);
        }
    }
    cout << "\nMST Edge List:\n";
    for (int i = 0; i < (int)mst.size(); i++) {
        cout << mst[i].u << " " << mst[i].v << " " << mst[i].w << endl;
    }
    cout << "\nTotal COST of MST: " << totalWeight << endl;
    return 0;
}
