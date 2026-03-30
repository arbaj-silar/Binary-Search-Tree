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

void inorder(Node* root) {
    if(root == NULL) return;
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

Node* buildBST(vector<int>& arr) {
    Node* root = NULL;
    
    for(int val: arr) {
        root = insert(root, val);
    }
    return root;
}

Node* pres = NULL;
Node* first = NULL;
Node* sec = NULL;

void inorderTree(Node* root) {
    if(root == NULL) return;

    inorderTree(root->left);
    if(pres != NULL && pres->data > root->data) {
        if(first == NULL) {
            first = pres;
        }
        sec = root;
    }
    pres = root;
    inorderTree(root->right);
}

void recoverTree(Node* root) {
    inorderTree(root);

    int temp = first->data;
    first->data = sec->data;
    sec->data = temp;
}

int main() {
    vector<int> arr = {3, 2, 1, 5, 6, 4};

    Node* root = buildBST(arr);
    inorder(root);
    return 0;
}