#include <bits/stdc++.h>
using namespace std;
void bucketSort(vector<int>& arr) {
    int n = arr.size();
    if (n <= 0) return;
    int max = *max_element(arr.begin(), arr.end());
    int bucketCount = n;
    vector<vector<int>> buckets(bucketCount);
    for (int i = 0; i < n; i++) {
        int idx = (arr[i] * bucketCount)/(max + 1);
        buckets[idx].push_back(arr[i]);
    }
    for (int i = 0; i < bucketCount; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }
    int index = 0;
    for (int i = 0; i < bucketCount; i++) {
        for (int val : buckets[i]) {
            arr[index++] = val;
        }
    }
}
int main() {
    vector<int> arr = {42, 32, 33, 52, 37, 47, 51};
    cout << "Before Sorting: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    bucketSort(arr);
    cout << "After Sorting: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
}
