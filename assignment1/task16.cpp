#include <iostream>
using namespace std;

int binarySearch(int arr[], int start, int end, int target) {
    if (start > end)  // base case: not found
        return -1;
    int mid = start + (end - start) / 2;

    if (arr[mid] == target)
        return mid;
    else if (arr[mid] > target)
        return binarySearch(arr, start, mid - 1, target);
    else
        return binarySearch(arr, mid + 1, end, target);
}

int main() {
    int n, target;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> target;

    int result = binarySearch(arr, 0, n - 1, target);
    if (result != -1)
        cout << "Element found at index " << result;
    else
        cout << "Element not found";
    return 0;
}