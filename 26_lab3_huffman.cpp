#include <bits/stdc++.h>
using namespace std;
struct Node {
    char ch;
    int count;
    Node *left;
    Node *right;
    Node(char c, int f, Node* l=nullptr, Node* r=nullptr)
        : ch(c), count(f), left(l), right(r) {}
};
struct Cmp {
    bool operator()(const Node* a, const Node* b) const {
        return a->count > b->count;
    }
};
void printCodes(Node* root, const string& path) {
    if (!root) return;
    if (!root->left && !root->right) {
        cout << (root->ch == ' ' ? "' '" : string(1, root->ch)) 
             << " : " << (path.empty() ? "0" : path) << "\n";
        return;
    }
    printCodes(root->left,  path + "0");
    printCodes(root->right, path + "1");
}
void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}
int main() {
    string s;
    getline(cin, s);
    map<char,int> count;
    for (char c : s) count[c]++;
    priority_queue<Node*, vector<Node*>, Cmp> pq;
    for (auto& p : count) {
        pq.push(new Node(p.first, p.second));
    }
    if (pq.size() > 1) {
        while (pq.size() > 1) {
            Node* a = pq.top(); pq.pop();
            Node* b = pq.top(); pq.pop();
            Node* parent = new Node('\0', a->count + b->count, a, b);
            pq.push(parent);
        }
    }
    Node* root = pq.top();
    cout << "Huffman Codes:\n";
    printCodes(root, "");
    freeTree(root);
    return 0;
}
