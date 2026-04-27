#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& nums, int left, int mid, int right) {
    vector<int> temp;
    int i = left, j = mid + 1;

    while (i <= mid && j <= right) {
        if (nums[i] < nums[j])
            temp.push_back(nums[i++]);
        else
            temp.push_back(nums[j++]);
    }

    while (i <= mid) temp.push_back(nums[i++]);
    while (j <= right) temp.push_back(nums[j++]);

    for (int k = 0; k < temp.size(); k++) {
        nums[left + k] = temp[k];
    }
}

void mergeSort(vector<int>& nums, int left, int right) {
    if (left >= right) return;

    int mid = (left + right) / 2;

    mergeSort(nums, left, mid);
    mergeSort(nums, mid + 1, right);
    merge(nums, left, mid, right);
}

int main() {
    vector<int> nums = {5, 2, 9, 1, 5, 6};

    mergeSort(nums, 0, nums.size() - 1);

    for (int x : nums)
        cout << x << " ";

    return 0;
}