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

Node* pre = NULL;

int minDifference(Node* root) {
    if(root == NULL) return INT32_MAX;

    int ans = INT32_MAX;
    if(root->left != NULL) {
        int leftDiff = minDifference(root->left);
        ans = min(leftDiff, ans);
    } 
    if(pre != NULL) {
        ans = min(ans, root->data-pre->data);
    }
    pre = root;
    
    if(root->right != NULL) {
        int rightDiff = minDifference(root->right);
        ans = min(rightDiff, ans);
    } 

    return ans;
}

int main() {
    vector<int> arr = {-10, -5, -2, 1, 5};

    Node* root = buildBST(arr);
    cout<<minDifference(root);
    return 0;
}