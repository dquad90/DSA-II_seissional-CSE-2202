#include <bits/stdc++.h>
using namespace std;
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    while (true) {
        if (i <= high && arr[i] <= pivot) {
            i++;
        } 
        else if (j >= low && arr[j] > pivot) {
            j--;
        } 
        else {
            if (i < j) {
                swap(arr[i], arr[j]);
                i++;
                j--;
            } else {
                break;
            }
        }
    }
    swap(arr[low], arr[j]);
    return j;
}
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
    cin >> arr[i];}
    quickSort(arr, 0, n - 1);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}
