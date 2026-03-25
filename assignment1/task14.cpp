#include <iostream>
using namespace std;
int search(int arr[], int n, int target) {
    if (n == 0) return 0;
    if (arr[n - 1] == target)
        return 1;
    else
        return search(arr, n - 1, target);
}

int main() {
    int n, t;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> t;
    if (search(arr, n, t) == 1) {
        cout << "found" << endl;
    }
    else {
        cout << "not found" << endl;
    }
    return 0;
}