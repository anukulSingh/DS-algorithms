#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node (int x) {
        data = x;
        next = NULL;
    }
};

// adv
// can traverse whole array from any linked list
// implement algos like round robin
// can insert at start or end , by maintaining one tail pointer, (useful in queues)

void printList (Node *head) {
    if (head == NULL) return;
    Node *p = head;
    do {
        cout << p->data<<" ";
        p = p->next;
    }
    while(p != head);
}

int main() {

    Node *head = new Node(10);
    head->next = new Node(5);
    head->next->next = new Node(20);
    head->next->next->next = new Node(15);
    head->next->next->next->next = head;

    return 0;
}