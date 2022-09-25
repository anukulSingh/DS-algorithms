#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *prev;
    Node *next;
    Node (int d) {
        data = d;
        prev = NULL;
        next = NULL;
    }
};

// printing all
void printList (Node *head) {
    Node *curr = head;
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

// insert at begin
Node *insertbegin (Node *head, int data) {
    Node *temp = new Node(data);
    temp->next = head;
    if (head != NULL)
        head->prev = temp;
    return temp;
}

// insert at end 
Node *insertEnd (Node *head, int data) {
    Node *temp = new Node(data);
    if (head == NULL) return temp;
    Node *curr = head;
    while (curr->next != NULL)
        curr = curr->next;
    curr->next = temp;
    temp->prev = curr;
    return head;
}

// reverse a dll
Node *reversedll (Node *head, int data) {
    if (head == NULL || head->next == NULL) return head;
    Node *prev = NULL, curr = head;
    while (curr != NULL) {
        // swapping curr->prev amd curr->next
        prev = curr->prev;
        curr->prev = curr->next;
        curr->next = prev;

        // update current node
        curr = curr->prev;
    }
    return prev->prev;
}

// delete at head
Node *deleteHead (Node *head) {
    if (head == NULL) return NULL;
    if (head->next == NULL) {
        delete head;
        return NULL;
    }
    Node *temp = head;
    head = head->next;
    head->prev = NULL;
    delete temp;
    return head;
}

// delete tail of a dll
Node *deleteTail (Node *head) {
    if (head == NULL) return NULL;
    if (head->next == NULL) {
        delete head;
        return NULL;
    }
    Node *curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->prev->next = NULL;
    delete curr;
    return head;
}


int main() {

    Node *head = new Node(10);
    Node *temp1 = new Node(20);
    Node *temp2 = new Node(30);
    head->next = temp1;
    temp1->prev = head;
    temp1->next = temp2;
    temp2->prev = temp1;
    printList(head);
    return 0;
}