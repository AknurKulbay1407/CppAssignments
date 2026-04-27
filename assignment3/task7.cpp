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

// 🔹 check mirror
bool isMirror(Node* a, Node* b) {
    if (a == nullptr && b == nullptr)
        return true;

    if (a == nullptr || b == nullptr)
        return false;

    return (a->val == b->val)
        && isMirror(a->left, b->right)
        && isMirror(a->right, b->left);
}

// 🔹 main function
bool isSymmetric(Node* root) {
    if (root == nullptr) return true;
    return isMirror(root->left, root->right);
}

int main() {
    // Example 1
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(4);
    root->right->right = new Node(3);

    cout << isSymmetric(root); // 1 (true)

    return 0;
}