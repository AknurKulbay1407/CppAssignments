#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void removeLast(Node*& head) {
    if (head == nullptr) return;
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}

int main() {
    Node* head = new Node{10, new Node{20, new Node{30, nullptr}}};
    removeLast(head);
    return 0;
}