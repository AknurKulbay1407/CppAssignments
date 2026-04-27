#include <iostream>
#include <vector>
#include <queue>
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

vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>> result;

    if (root == nullptr) return result;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size(); // сколько элементов в уровне
        vector<int> level;

        for (int i = 0; i < size; i++) {
            Node* cur = q.front();
            q.pop();

            level.push_back(cur->val);

            if (cur->left != nullptr)
                q.push(cur->left);

            if (cur->right != nullptr)
                q.push(cur->right);
        }

        result.push_back(level);
    }

    return result;
}

int main() {
    // [3,9,20,null,null,15,7]
    Node* root = new Node(3);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);

    vector<vector<int>> res = levelOrder(root);
    cout << "[ ";
    for (auto& level : res) {
        cout << "[ ";
        for (int x : level) cout << x << " ";
        cout << "]\n";
    }
    cout << "] ";
    return 0;
}