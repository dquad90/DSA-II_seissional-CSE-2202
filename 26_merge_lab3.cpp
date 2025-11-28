#include <iostream>
using namespace std;
void mergeArrays(int arr1[], int n, int arr2[], int m, int arr3[]) {
    int i = 0, j = 0, k = 0;
    while (i < n && j < m) {
        if (arr1[i] >= arr2[j]) {
            arr3[k] = arr1[i];
            k++;
            i++;
        } else {
            arr3[k] = arr2[j];
            k++;
            j++;
        }
    }
    while (i < n) {
        arr3[k] = arr1[i];
        k++;
        i++;
    }
    while (j < m) {
        arr3[k] = arr2[j];
        k++;
        j++;
    }
}
int main() {
    int n = 5, m = 3;
    int arr1[] = {6, 5, 4, 3, 2};  
    int arr2[] = {8, 7, 6};       
    int arr3[n + m];
    mergeArrays(arr1, n, arr2, m, arr3);
    for (int x = 0; x < n + m; x++) {
        cout << arr3[x] << " ";
    }
    return 0;
}

