#include <bits/stdc++.h>
using namespace std;


struct node  
{ 
  int key; 
  struct Node *left;
  struct Node *right; 
  Node(int k){
      key=k;
      left=right=NULL;
  }
};

// insert in a bst
node *insert (node *root, int x) {
    if (!root) return new node(x);
    if (root->key < x) // insert in sright subtree
        root->right = insert(root->right, x);
    else if (root->key > x) // inserty on left side
        root->left = insert(root->left, x);

    return root;
}

// search in a bst
bool search (node *root, int x) {
    while (!root) {
        if (root->key == x)
            return true;
        else if (root->key < x)
            root = root->right;
        else
            root = root->left;
    }
    return false;
}


// ceiling of all the left side elements in an array
// smallest element larger than the given element
// i.e el gte than the given one on the left
// lower_bound() in set works as such
// at one snapshot, we only need leftmost part of the element, so we may insert it one by one
void printCeilingLeft (int *arr, int n) {
    cout << -1 << " "; // for first element
    set <int> s;
    s.insert(arr[0]);
    for (int i = 1;i < n; ++i) {
        if (s.lower_bound(arr[i]) != s.end()) {
            cout << *(s.lower_bound(arr[i])) << " ";
        }
        else 
            cout << -1 << " ";
        s.insert(arr[i]);
    }
}

// ceiling on right side of an array
void printCeilingRight (int *arr, int n) {
    set<int> s;
    vector<int> ceilingRight;
    for (int i = n- 1; i>= 0; --i) {
        if (s.lower_bound(arr[i] != s.end())) {
            ceilingRight.push_back(*(s.lower_bound()));
        } else {
            ceilingRight.push_back(-1);
        }
        s.insert(arr[i]);
    }
}

// check for a bst
// define ranges for each node
// start with -inf to +inf
// for left child, we change the upper limit, for right lower
bool isBST(Node *root, int min, int max) {
    if (root == NULL) return true;
    return (
        root->key > min &&
        root->key < max &&
        isBST(root->left, min, root->key) &&
        isBST(root->right, root->key, max)
    );
}
// second efficient - if inorder traversal is sorted, then it is a BST
int prev = INT_MIN;
bool isBST(Node *root) {
    if (root == NULL) return true;
    if (!isBST(root->left)) return false;
    if (root->key <= prev) return false;
    prev = root->key;
    return (isBST(root->right));
}

// fix two swapped nodes
// do inorder, and push it in array, and in array find two eles swapping which, array becomes sorted
// now it becomes an array problem
Node *prev = NULL, *first = NULL, *second = NULL
void fixBST(Node * root) {
    if (root == NULL) return;
    fixBST(root->left);
    if (prev !== NULL && root->key < prev->key) { // prev != NULL ensures skippin root for first tym
        if (first == NULL)
            first = prev;
        second = root;
    }
    prev = root;
    fixBST(root->right);
}

// kth smallest element
// naive by inorder trav
void printByKth (npde *root, int k, int &count) {
    if (!root) return;
    printByKth(root->left, k, count);
    count++;
    if (count == k) {
        cout << root->key;
        return;
    }
    printByKth(root->right, k, count);
}

// find pair with given sum in bst
bool isPairSum (Node *root, int sum, unordered_set<int> &s) {
    if (root == NULL) return false;
    if (isPairSum(root->left, sum, s))
        return true;
    if (s.find(sum - root->key) != s.end())
        return true;
    else 
        s.insert(root->key);
    return isPairSum(root->right, sum, s);
}

// vertical sum in BT
// same horizontal dist
void verticalSumRec(Node *root, int hd, map<int , int> m) {
    if (root == NULL) return;
    verticalSumRec(root->left, hd-1, m);
    m[hd] += root->key;
    verticalSumRec(root->right, hd+1, m);
}
void verticalSum(Node *root) {
    map <int, int> m;
    verticalSumRec(root, 0, m);

    for (auto &x: m) {
        cout << x.second << " ";
    }
}

// vertical traversal
// we have to use level order traversal
void vTraversal(Node *root) {
    map <int, vector<int> > m;
    queue<pair <Node *, int> > q;
    q.push({ root, 0 });

    while (!q.empty()) {
        auto p = q.front();
        Node *curr = p.first;
        int hd = p.second;
        mp[hd].push_back(curr->key);
        q.pop();
        if (curr->left != NULL)
            q.push({ curr->left, hd - 1  });
        if (curr->right != NULL)
            q.push({ curr->right, hd + 1 });
    }

    for (auto &x: m) {
        cout << x.second << " ";
    }
}

//top view of BT
void topView(Node *root) {
    map <int, int> m;
    queue<pair <Node *, int> > q;
    q.push({ root, 0 });

    while (!q.empty()) {
        auto p = q.front();
        Node *curr = p.first;
        int hd = p.second;

        if (m.find(hd) == m.end())
            mp[hd] = curr->key;
        q.pop();

        if (curr->left != NULL) {
            q.push({ curr->left, hd-1 });
        }
        if (curr->right != NULL) {
            q.push({ curr->right, hd+1 });
        }
    }
    for (auto &x: m)
        cout << x.second << " ";
}

// Bottom view of BT
void bottomView(Node *root) {
    map <int, int> m;
    queue<pair<Node *, int> > q;
    q.push({ root, 0 });

    while(!q.empty()) {
        auto p = q.front();
        Node *curr = p.first;
        int hd = p.second;

        mp[hd] = curr->key;
        q.pop();

        if (curr->left != NULL) {
            q.push({ curr->left, hd-1 });
        }
        if (curr->right != NULL) {
            q.push({ curr->right, hd+1 });
        }
    }
    for (auto &x: m)
        cout << x.second << " ";
}

// pair with given sum

// make a ds which support kth smallest no in O(height) time
int main () {
    int arr[]={2,8,30,15,25,12};
    printCeiling(arr, 6);
    return 0;
}