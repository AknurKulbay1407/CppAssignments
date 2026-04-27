#include <iostream>
#include <unordered_map>
using namespace std;

int firstUniqChar(string s) {
    unordered_map<char, int> freq;

    // Step 1: count frequency
    for (char c : s) {
        freq[c]++;
    }

    // Step 2: find first unique
    for (int i = 0; i < s.size(); i++) {
        if (freq[s[i]] == 1) {
            return i;
        }
    }

    return -1;
}