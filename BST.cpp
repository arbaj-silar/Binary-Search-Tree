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

bool search(Node* root, int  val) {
    if(root == NULL) return false;
    if(root->data == val) return true;
    
    if(val>root->data) {
        return search(root->right, val);
    } else {
        return search(root->left, val);
    }
}

Node* getInorderSuccessor(Node* root) {
    while(root != NULL && root->left != NULL) {
        root = root->left;
    }
    return root;
}
Node* deleteNode(Node* root, int val) {
    if(root == NULL) return NULL;

    if(val<root->data) {
        root->left = deleteNode(root->left, val);
    } else if(val>root->data) {
        root->right = deleteNode(root->right, val);
    } else {
        if(root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if(root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        } else {
            Node* IS = getInorderSuccessor(root->right);
            root->data = IS->data;
            root->right = deleteNode(root->right, IS->data);
        }
    }
    return root;
}

int main() {
    vector<int> arr = {3, 2, 1, 5, 6, 4};

    Node* root = buildBST(arr);
    inorder(root);

    cout<<endl;
    cout<<search(root, 4)<<endl;
    Node* r = deleteNode(root, 5);
    
    inorder(r);
    return 0;
}