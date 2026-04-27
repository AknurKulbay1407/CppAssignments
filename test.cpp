#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
// void removelast (Node*& head) {
//     if (head == nullptr) return;
//     Node* temp = head;
//     while (temp->next->next != nullptr) {
//         temp = temp->next;
//     }
//     delete temp->next;
//     temp->next = nullptr;
// };

//Write a function to reverse a singly linked list (reverse). The function reverses (reverses) a singly
//linked list:
void reverse(Node*& head) {
    Node* rev = nullptr;
    Node* temp = head;
    while (temp-> next != nullptr) {
        temp = temp->next;
    }

    temp->next = rev;
    rev = temp;

}


int main() {
    Node* head = new Node{1, new Node{2, new Node{3, nullptr}}};
    removelast(head);
};
