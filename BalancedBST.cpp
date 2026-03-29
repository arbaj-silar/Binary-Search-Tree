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

Node* helper(vector<int>& arr, int st, int end) {
    if(st > end) return NULL;

    int mid = st + (end-st)/2;
    Node* root = new Node(arr[mid]);

    root->left = helper(arr, st, mid-1);
    root->right = helper(arr, mid+1, end);

    return root;
}

Node* sortedArrayBST(vector<int> &arr) {
    helper(arr, 0, arr.size()-1);
}

void inorder(Node* root) {
    if(root == NULL) return;
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main() {
    vector<int> arr = {-10, -3, 0, 1, 5};

    Node* root = sortedArrayBST(arr);
    return 0;
}