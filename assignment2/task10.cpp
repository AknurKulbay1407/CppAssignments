#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertionSort(Node*& head) {
    Node* sorted = nullptr;
    Node* curr = head;
    while (curr != nullptr) {
        Node* nextStep = curr->next;
        if (sorted == nullptr || sorted->data >= curr->data) {
            curr->next = sorted;
            sorted = curr;
        } else {
            Node* temp = sorted;
            while (temp->next != nullptr && temp->next->data < curr->data) {
                temp = temp->next;
            }
            curr->next = temp->next;
            temp->next = curr;
        }
        curr = nextStep;
    }
    head = sorted;
}

int main() {
    Node* head = new Node{3, new Node{1, new Node{2, nullptr}}};
    insertionSort(head);
    return 0;
}