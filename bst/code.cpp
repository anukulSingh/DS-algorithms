#include <iostream>
using namespace std;

struct Node {
    int key;
    Node *left, *right;
    Node (int x) {
        key = x;
        left = right = NULL;
    }
};
// to keep height always log n, we have to check height
// for skewed tree, this is a problem
// if we knew key in advance, we can avoid this by making a balanced tree
// we can restructure(rotation), to prevent it from becoming a unbalanced tree, if keys are taken as input

bool search (Node *root, int x) {
    while (root != NULL) {
        if (root->key == x) return true;
        else if (root->key < x)
            root = root->right;
        else
            root = root->left;
    }
    return false;
}




int main() {
    Node *root=new Node(15);
	root->left=new Node(5);
	root->left->left=new Node(3);
	root->right=new Node(20);
	root->right->left=new Node(18);
	root->right->left->left=new Node(16);
	root->right->right=new Node(80);

    search(root, x) ? cout << "Found" : cout << "Not found";
}