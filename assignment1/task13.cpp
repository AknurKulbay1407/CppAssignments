#include <iostream>
using namespace std;
int count(int arr[], int n, int target) {
    if (n == 0) return 0;
    if (arr[n - 1] == target)
        return 1 + count(arr, n - 1, target);
    else
        return count(arr, n - 1, target);
}

int main() {
    int n, t;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> t;
    cout << count(arr, n, t);
    return 0;
}