#include <iostream>
#include <queue>
using namespace std;

class node {
    public:
        int data;
        node *left;
        node *right;

        node (int d) {
            data = d;
            left = right = NULL;
        }
        void preorder(node *root) {
            if (root != NULL) {
                cout<< root->data << " ";
                preorder(root->left);
                preorder(root->right);
            }
        }
        void inorder(node *root) {
            if (root == NULL)
                return;
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
        void postorder (node *root) {
            if (root == NULL)
                return;
            postorder(root->left);
            postorder(root->right);
            cout << root->data << " ";
        }
        int height (node *root) {
            if (root == NULL)
                return 0;
            return max(height(root->left), height(root->right)) + 1;
        }
        // // print nodes at k distance from root
        // // print nodes at k+1 th level
        void printKDist(node *root, int k) {
            if (root == NULL) return;
            if (k == 0) cout << root->data << " ";
            else {
                printKDist(root->left, k-1);
                printKDist(root->right, k-1);
            }
        }

        
};
// level -order traversal using a queue
        void printLevel (node *root) {
            if (root == NULL) return;
            queue <node *> q;
            q.push(root);
            while (!q.empty()) {
                node *curr = q.front();
                q.pop();
                cout << curr->data;
                if (curr->left != NULL) 
                    q.push(curr->left);
                if (curr->right != NULL)
                    q.push(curr->right);
            }
        }
// level order traversal hierarchical printing
void printLevelMod(node *root) {
    if (root == NULL) return;
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (q.size() > 1) {
        node *curr = q.front();
        q.pop();
        if (curr == NULL) {
            cout << "\n";
            q.push(NULL);
            continue;;
        }
        cout << curr->data;
        if (curr->left != NULL) 
            q.push(curr->left);
        if (curr->right != NULL)
            q.push(curr->right);
    }
} 
// second method of level traversal (level by level enqueing)
        void printLevelIterative (node *root) {
            if (root == NULL) return;
            queue <node *> q;
            q.push(root);
            while (!q.empty()) {
                int count = q.size();
                for (int i = 0; i < count; ++i) {
                    node *curr = q.front();
                    q.pop();
                    cout << (curr->data) << " ";
                    if (curr->left != NULL)
                        q.push(curr->left);
                    if (curr->right != NULL)
                        q.push(curr->right);
                }
                cout << "\n";
            }
        }
    
// size of a binary tree
// TC O(n) AS is O(h)
// at any time, there are at most h+1 function calls in stack
// if we use iterative solution using queue(level order,) it will have O(w) AS width of the tree
// int getSize (node *root) {
//     if (root == NULL) return 0;
//     return 1 + getSize(root->left) + getSize(root->right);
// }

// maximum in binary tree
// TC and AS like previous
// if tree is skewed, level order  traversal is better, if perfect tree, then recursive is better (for AS)
// int getMax (node *root) {
//     if (root == NULL)
//         return INT_MIN;
//     return max(root->key, max(getMax(root->left), getMax(root->right)));
// }
int main() {
    node *root = new node(10);
    root->left = new node(20);
    root->right = new node(30);
    root->right->left = new node(40);
    root->right->right = new node(50);

    //root->preorder(root); // 10 20 30 40 50  DLR
    // root->inorder(root); // 20 10 40 30 50 LDR
    // root->postorder(root);  // 20 40 50 30 10  LRD
    // cout << root->height(root);


    // root->printKDist(root, 2); // at second level
    // root->printLevel(root); // 10 20 30 40 50

    root->left->left = new node(60);  
    // printLevelIterative(root); // 10 20 30 60 40 50
    cout << getSize(root);
}
