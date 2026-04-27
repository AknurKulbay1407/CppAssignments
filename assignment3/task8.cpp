#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int v) {
        val = v;
        left = right = nullptr;
    }
};

int maxLen = 0;

void dfs(Node* node, Node* parent, int length) {
    if (node == nullptr) return;

    if (parent != nullptr && node->val == parent->val + 1) {
        length++;
    } else {
        length = 1;
    }

    if (length > maxLen)
        maxLen = length;

    dfs(node->left, node, length);
    dfs(node->right, node, length);
}

int longestConsecutive(Node* root) {
    dfs(root, nullptr, 0);
    return maxLen;
}

int main() {
    // [1,null,3,2,4,null,null,null,5]

    Node* root = new Node(1);
    root->right = new Node(3);
    root->right->left = new Node(2);
    root->right->right = new Node(4);
    root->right->right->right = new Node(5);

    cout << longestConsecutive(root); // Output: 3

    return 0;
}