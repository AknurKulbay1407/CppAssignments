#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void combineLists(Node*& head1, Node* head2) {
    if (head1 == nullptr) {
        head1 = head2;
        return;
    }
    Node* temp = head1;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = head2;
}

int main() {
    Node* L1 = new Node{1, new Node{2, nullptr}};
    Node* L2 = new Node{3, new Node{4, nullptr}};
    combineLists(L1, L2);
    return 0;
}