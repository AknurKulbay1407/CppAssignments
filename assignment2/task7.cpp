#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void removeByValue(Node*& head, int value) {
    if (head == nullptr) return;
    if (head->data == value) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != value) {
        temp = temp->next;
    }
    if (temp->next != nullptr) {
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }
}

int main() {
    Node* head = new Node{10, new Node{20, new Node{30, nullptr}}};
    removeByValue(head, 20);
    return 0;
}