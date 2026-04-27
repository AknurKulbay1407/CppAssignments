#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

bool sfawtde(Node* head, int target) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == target) return true;
        temp = temp->next;
    }
    return false;
}

int main() {
    Node* head = new Node{5, new Node{10, new Node{15, nullptr}}};
    if (sfawtde(head, 10)) cout << "Found" << endl;
    return 0;
}