#include <iostream>
using namespace std;
int suma(int n) {
    if (n == 0) return 0;
    return 1 + suma(n / 10);  // recursive step
}
int main() {
    int n;
    cin >> n;
    cout <<suma(n);
    return 0;
}