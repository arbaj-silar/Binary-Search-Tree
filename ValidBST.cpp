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

bool helper(Node* root, Node* min, Node* max) {
    if(root == NULL) return true;

    if(min != NULL && root->data <= min->data) {
        return false;
    }
    if(max != NULL && root->data >= max->data) {
        return false;
    }
    return helper(root->left, min, root) &&
            helper(root->right, root, max);
}

bool isBST(Node* root) {
    return helper(root, NULL, NULL);
}

int main() {
    vector<int> arr = {3, 2, 1, 5, 6, 4};

    Node* root = buildBST(arr);
    cout<<isBST(root);
    return 0;
}