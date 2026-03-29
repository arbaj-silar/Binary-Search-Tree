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
int prevOrder = 0;
int kthSmallest(Node* root, int k) {
    if(root == NULL) return -1;

    if(root->left != NULL) {
        int leftAns = kthSmallest(root->left, k);
        if(leftAns != -1) return leftAns;
    }
    
    if(prevOrder+1 == k) {
        return root->data;
    }
    
    prevOrder += 1;
    if(root->right != NULL) {
        int rightAns = kthSmallest(root->right, k);
        if(rightAns != -1) return rightAns;
    }

    return -1;
}

int main() {
    vector<int> arr = {-10, -5, -2, 1, 5};

    Node* root = buildBST(arr);
    cout<<kthSmallest(root, 4);
    return 0;
}