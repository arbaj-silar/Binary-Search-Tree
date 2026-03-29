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

Node* helper(vector<int> &preorder, int& i, int bound) {
    if(i >= preorder.size() || preorder[i]>bound) return NULL;

    Node* root = new Node(preorder[i++]);
    root->left = helper(preorder, i, root->data);
    root->right = helper(preorder, i, bound);

    return root;
}

Node* bstFromPreorder(vector<int>& preorder) {
    int i = 0;
    return helper(preorder, i, INT32_MAX);
}
void inorder(Node* root) {
    if(root == NULL) return;
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main() {
    vector<int> preorder = {6, 3, 1, 4, 8, 9};

    Node* root = bstFromPreorder(preorder);
    inorder(root);
    return 0;
}