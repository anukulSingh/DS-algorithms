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

int maxLevel = 0;

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


void printLeftRecursive(node *root) {
    if (root == NULL) return ;
    if (maxLevel < level) {
        cout << root->key;
        maxLevel = level;
    }
    printLevelRecursive(root->left, level+1);
    printLevelRecursive(root->right, level + 1);

}


void printLeft(node *root) {
    if (root == NULL) return;
    queue<node*> q;
    q.push(root);

    while (!q.empty()) {
        int count = q.size();
        for (int i = 0; i < count; ++i) {
            node *curr = q.top();
            q.pop();
            if (i == 0)
                cout << curr->key;
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);

        }
    }
}

// children sum property
// sum of sum of values of left and right child should be equal to that of the node value
bool isChildrenSum(node *root) {
    if (root == NULL) return true;
    if (root->left == NULL && root->right == NULL) return true;
    int sum = 0;
    if (root->left) sum += root->left->key;
    if (root->right) sum += root->right->key;

    return (
        root->key == sum &&
        isChildrenSum(root->left) &&
        isChildrenSum(root->right)
    );
}


// check for a balanced BT
// diff bw right subtree and left subtree for any node should not exceed 1
// Naive way
bool checkBalanced (node *root) {
    if (root == NULL) return true;
    int lh = height(root->left);
    int rh = height(root->right);

    return (
        abs(lh - rh) <= 1 &&
        checkBalanced(lh->left) &&
        checkBalanced(lh->right)
    );
}

// efficient
int checkBalanced(node *root) {
    if (root == NULL) return 0;
    int lh = checkBalanced(root->left);
    if (lh == -1) return -1;
    int rh = checkBalanced(root->right)
    if (rh == -1) return -1;

    if (abs(lh - rh) > 1) return -1;
    else return max(lh, rh) + 1;
}

// max width of binar7 tree at any level
int maxWidth (node *root) {
    if (root == NULL) return 0;
    queue<node*> q;
    q.push(root);
    int res = INT_MIN;
    while (!q.empty()) {
        int count = q.size();
        ans = max(ans, count);
        for (int i = 0; i < count; ++i) {
            node *curr = q.front();
            q.pop();

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->righ);
        }
    }
    return res;
}




// convet binary tree to doubly linked list in place
// use an inorder travesal
// use left for prev and right for next
node *prev = NULL;
node* convertToDll(node *root) {
    if (root == NULL) return root;
    node *head = convertToDll(root->left);
    if (prev == NULL) head = root;
    else {
        root->left = prev;
        prev->right = right;
    }
    prev = root;
    convertToDll(root->right);
    return head;
}

// given inorder and preorder travesal, construct the tree
// we can get the root at all level from preorder
// and left amd right tree for inorder

// an efficient way is to take hashset and use it
int preIndex = 0;
node *cTree(int *int, int *pre, int is, int ie) {
    if (is > ie) return NULL;

    node *root = new Node(pre[preIndex++]);
    int inIndex;
    for (int i = is; i <= ie; ++i) {
        if (in[i] == root->key) {
            inIndex = i;
            break;
        }
    }
    root->left = cTree(in, pre, is, inIndex - 1);
    root->right = cTree(in, pre, inIndex, ie);
}

// LCA of a node in binary tree

    
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
