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

int main() {

    
    return 0;
}