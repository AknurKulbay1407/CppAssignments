// 2. Implement a function to add an element to the end of a singly linked list.
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};

void putAtEnd (Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    Node* last = head;
    while (last->next != nullptr) {
        last = last->next;
    }
    last->next = newNode;
}

int main() {
    Node* head = nullptr;

    return 0;
}