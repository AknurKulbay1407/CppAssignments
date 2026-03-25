#include <iostream>
using namespace std;
int pali(int start, int end, string n) {
    if (start >= end)  // base case
        return 1;
    if (n[start] != n[end])  // mismatch
        return 0;
    return pali( start + 1, end - 1, n);  // recursive step
}
int main() {
    string n;
    cin >> n;
    if (pali(0, n.length() - 1, n) == 1)
        cout << "Palindrome";
    else
        cout << "Not Palindrome";
    return 0;
}