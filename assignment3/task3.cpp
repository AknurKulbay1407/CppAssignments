#include <iostream>
#include <unordered_map>
using namespace std;

bool isIsomorphic(string s, string t) {
    unordered_map<char, char> mapST;
    unordered_map<char, char> mapTS;

    for (int i = 0; i < s.size(); i++) {
        char c1 = s[i];
        char c2 = t[i];

        if (mapST.count(c1)) {
            if (mapST[c1] != c2) return false;
        } else {
            mapST[c1] = c2;
        }

        if (mapTS.count(c2)) {
            if (mapTS[c2] != c1) return false;
        } else {
            mapTS[c2] = c1;
        }
    }

    return true;
}

int main() {
    string s = "egg";
    string t = "add";

    bool result = isIsomorphic(s, t);

    if (result)
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}