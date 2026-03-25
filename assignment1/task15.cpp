#include <iostream>
using namespace std;

int isSorted(int arr[], int n) {
    if (n == 1) return 1;  // base case
    if (arr[n - 1] < arr[n - 2])
        return 0;
    return isSorted(arr, n - 1);
}
int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    if (isSorted(arr, n) == 1) {
        cout << "Sorted";
    }
    else {
        cout << "Not sorted";
    }
    return 0;
}