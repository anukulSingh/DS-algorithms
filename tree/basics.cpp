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

// get the size of the tree
int getSize(node *root) {
    if (root == NULL) return 0;
    return 1 + getSize(root->left) + getSize(root->right);
}

// maximum of a B-tree
int getMax(node *root) {
    if (root == NULL) return INT_MIN;
    return max(root->key, max(getMax(root->left), getMax(root->right)));
}



// children sum property
// sum of sum of values of left and right child should be equal to that of the node value
bool isChildrenSum(node *root) {
    if (root == NULL) return true;
    if (root->left == NULL && root->right == NULL) return true; // we are accesssing left amd right child below, so we have to check for existence, if bot null,
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
    if (prev == NULL) head = root; // to identify for the first node of LL only
    else {
        root->left = prev;  // visualize left as prev ptr
        prev->right = root; // visualize right as next ptr
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


// tree traversal in spiral form
//in one level left to right, then right to left in next level , the so on
// method 1
// we can maintain s stack and flag to know when the reverse way has to printed

 vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        queue<TreeNode *> q;
        stack<TreeNode *> s;
        vector<vector<int> > ans;
        if (root == NULL) return ans;

        q.push(root);
        bool reverse = false;
        while (!q.empty()) {
            int count = q.size();
            vector<int> res;
            for (int i = 0; i < count; ++i) {
                TreeNode *curr = q.front();
                q.pop();
                if (reverse) {
                    s.push(curr);
                } else {
                    res.push_back(curr->val);
                }

                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            while (!s.empty()) {
                res.push_back(s.top()->val);
                s.pop();
            }
            ans.push_back(res);
            reverse = !reverse;
        }
        return ans;
    }

// diameter of a B-tree
// longest path in tree bw any two leaf nodes
// naive find 1 + max  (lh, rh) fofr evrry node
// efficient now
    int diameter = 0;
    
    int height(TreeNode* root) {
        if (root == NULL) return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        
        diameter = max(diameter, 1 + lh + rh);
        return 1 + max(lh, rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int h = height(root);
        return diameter - 1;
    }


// size of a binary tree
// TC O(n) AS is O(h)
// at any time, there are at most h+1 function calls in stack
// if we use iterative solution using queue(level order,) it will have O(w) AS width of the tree
int getSize (node *root) {
    if (root == NULL) return 0;
    return 1 + getSize(root->left) + getSize(root->right);
}

// maximum in binary tree
// TC and AS like previous
// if tree is skewed, level order  traversal is better, if perfect tree, then recursive is better (for AS)
int getMax (node *root) {
    if (root == NULL)
        return INT_MIN;
    return max(root->key, max(getMax(root->left), getMax(root->right)));
}

// lca between two nodes
// using lca, we can also find shortest distance bw tow nodes in a binary tree
// method 1
// make two paths for both nodes, and the last common element from left is our answer
bool findPath (node *root, vector<node *> &p, int n) {
    if (root == NULL) return false;
    p.push_back(root);
    if (root->key == n) return true;
    if (findPath(root->left, p, n) || findPath(root->right, p, n)) return true;
    p.pop_back();
    return false;
}
node *lca (node *root, int n1, int n2) {
    vector<node *> path1, path2;
    // if any of the tow nodes are not there in the tree, it should not return anything
    if (findPath(root, path1, n1) == false || findPath(root, path2, n2) == false) {
        return nullptr;
    }
    // path1 and path2 are filled now
    for (int i = 0; i < path1.size() -1 && i < path2.size() - 1; ++i) {
        if (path1[i+1] != path2[i+1]) {
            return path[i];
        }
    }
    return nullptr;
}

// efficient lca
// gives incorrect result if keys are not present in the tree
// one traversal an O(h) AS
node *lca ()

// burn a binary tree from leaf 
// so that whole binary tree burns
// it is same as finding the distnace of farthest node from the given leaf node
// tim etaken = farthest distance
int res = 0;
int timeToBurn(node *tree, int leaf, int &dist) {

}
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
