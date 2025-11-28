#include <iostream>
using namespace std;
void sprime(int n, int div = 2) {
    if (n < 2) return;
    if (div * div > n) {
        cout << n << " ";
        return;
    }
    if (n % div == 0) return; 
    sprime(n, div + 1);
}
void printPrime(int arr[], int left, int right) {
    if (left == right) {
        sprime(arr[left]);  
        return;
    }
    int mid = (left + right) / 2;
    printPrime(arr, left, mid);
    printPrime(arr, mid + 1, right);
}
int main() {
    int arr[100];
    int n;
    cout << "Enter elements: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Prime numbers in the array: ";
    printPrime(arr, 0, n - 1);
    cout << endl;
    return 0;
}


