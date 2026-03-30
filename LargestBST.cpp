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

void inorder(Node* root) {
    if(root == NULL) return;
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

class Info {
public:
    int min, max, size;

    Info(int min, int max, int size) {
        this->max = max;
        this->min = min;
        this->size = size;
    }
};

Info helper(Node* root) {
    if(root == NULL) {
        return Info(INT32_MAX, INT32_MIN, 0);
    }

    Info left = helper(root->left);
    Info right = helper(root->right);

    if(root->data > left.max && root->data < right.min) {
        int currMin = min(root->data, left.min);
        int currMax = max(root->data, right.max);
        int currSz = left.size+right.size+1;

        return Info(currMin, currMax, currSz);
    }

    return Info(INT32_MIN, INT32_MAX, max(left.size, right.size));
}

int largestBSTinBT(Node* root) {
    Info in = helper(root);
    return in.size;
}   

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->left->left = new Node(2);
    root->left->right = new Node(7);
    root->right = new Node(11);
    root->right->right = new Node(4);

    inorder(root);
    cout<<endl;
    cout<<largestBSTinBT(root);
    return 0;
}