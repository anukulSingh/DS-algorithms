#include <iostream>
using namespace std;

// detect loop in linked list
// one way is to maintain a visited array
// can also use hash set

// floyd's cycle detection
// slow and fast pointer
// maintain sslow (1 step) and fast(2 steps) pointers
// we claim that if there is a loop, they meet somewhere
// if not, then one of them becomes null
bool isLoop (node *head) {
    node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }
    return false;
}


// detect and remove loop
// detect loop using floyd algo
// take slow to the start of LL, and fast at the meet point
// now start inc them at same speed
// the point where they meet is the new head of linked list
void detectRemoveLoop (node *head) {
    node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            break;
    }

    if (slow != fast)
        return;

    slow = head;
    while (slow->next && fast->next) {
        slow = slow->next;
        fast = fast->next;
    }
    // fast is the last node of the loop now, and slow->next is the first
    // loop is bw fast and slow->next
    fast->next = NULL; // remove that loop branch
}

// variatiions
// 1. length of the loop
// after detection, fix one of the pointers at the meet point, and start to traverse from it's next
// until they meet again, keep increasing count and keep track of length
// 2. find first node of loop


// delete a node with only pointer given to it
void deleteNode (node *ptr) {
    node *temp = ptr->next;
    ptr->data = temp->data;
    ptr->next = temp->next;
    delete(temp);
}



// merge twi sorted LL
// we have to maintain 2 pointers
// a and b
// and also maintain a tail pointer
// TC O(m + n)
node *sortedMerge (node *a, node *b) {
    // if anb LL is empty
    if (a == NULL) return b;
    if (b == NULL) return a;

    // initializing head an tail in for smaller head, and move one step in that LL
    node *head = NULL, *tail = NULL;
    if (a->data <= b->data) {
        head = tail = a;
        a = a->next;
    } else {
        head = tail = b;
        b = b->next; 
    }

    // our merge logic
    while (a != NULL && b != NULL) {
        if (a->data <= b->data) {
            tail->next = a;
            tail = a;
            a = a->next;
        } else {
            tail->next = b;
            tail = b;
            b = b->next;
        }
    }

    // remaining elements in one of the LL
    if (a != NULL) tail->next = a;
    else if (b != NULL) tail->next = b;

    return head;
}


int main() {

    
    return 0;
}