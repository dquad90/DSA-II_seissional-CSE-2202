#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, C;
    cout << "Enter number of items: ";
    cin >> n;
    vector<int> wt(n + 1), val(n + 1);
    cout << "Enter weights of items:\n";
    for (int i = 1; i <= n; i++) cin >> wt[i];
    cout << "Enter values of items:\n";
    for (int i = 1; i <= n; i++) cin >> val[i];

    cout << "Enter knapsack capacity: ";
    cin >> C;
    vector<vector<int>> dp(n + 1, vector<int>(C + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= C; ++w) {
            dp[i][w] = dp[i - 1][w]; 
            if (wt[i] <= w) {
                dp[i][w] = max(dp[i][w], val[i] + dp[i - 1][w - wt[i]]);
            }
        }
    }
    vector<int> cW;
    int w = C;
    for (int i = n; i >= 1; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            cW.push_back(wt[i]);
            w -= wt[i];
        }
    }
    reverse(cW.begin(), cW.end());

    cout << "\nMaximum value = " << dp[n][C] << "\n";
    cout << "Weights included: ";
    if (cW.empty()) cout << "none";
    else {
        for (int weight : cW) cout << weight << " ";
    }
    cout << "\n";

    return 0;
}


