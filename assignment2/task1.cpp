#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
void addnew (Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}
int main() {
    Node* head = nullptr;
    addnew(head, 10);
}