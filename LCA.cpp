#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* insert(Node* root, int val) {
    if(root == NULL) return new Node(val);

    if(val<root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

Node* buildBST(vector<int>& arr) {
    Node* root = NULL;
    
    for(int val: arr) {
        root = insert(root, val);
    }
    return root;
}

Node* lca(Node* root, Node* p, Node* q) {
    if(root == NULL) return NULL;

    if(root->data >p->data && root->data > q->data) {
        return lca(root->left, p, q);
    } else if(root->data < p->data && root->data < q->data) {
        return lca(root->right, p, q);
    } else {
        return root;
    }
}

Node* findNode(Node* root, int val) {
    if(root == NULL) return NULL;
    if(root->data == val) return root;

    Node* left = findNode(root->left, val);
    if(left) return left;

    return findNode(root->right, val);
}

int main() {
    vector<int> arr = {8, 2, 3, 4, 5, 6, 7, 9};

    Node* root = buildBST(arr);
    Node* p = findNode(root, 2);
    Node* q = findNode(root, 9);

    Node* ans = lca(root, p, q);
    cout<<ans->data<<endl;
    return 0;
}