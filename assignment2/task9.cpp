#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void reverse(Node*& head) {
    Node* prev = nullptr;
    Node* curr = head;
    Node* nextNode = nullptr;
    while (curr != nullptr) {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    head = prev;
}

int main() {
    Node* head = new Node{1, new Node{2, new Node{3, nullptr}}};
    reverse(head);
    return 0;
}