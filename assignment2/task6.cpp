#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertAtPosition(Node*& head, int value, int pos) {
    if (pos == 0) {
        head = new Node{value, head};
        return;
    }
    Node* temp = head;
    for (int i = 0; temp != nullptr && i < pos - 1; i++) {
        temp = temp->next;
    }
    if (temp != nullptr) {
        temp->next = new Node{value, temp->next};
    }
}

int main() {
    Node* head = new Node{1, new Node{3, nullptr}};
    insertAtPosition(head, 2, 1);
    return 0;
}