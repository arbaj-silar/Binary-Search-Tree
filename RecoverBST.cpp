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
void inorder(Node* root) {
    if(root == NULL) return;
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main() {
    Node* root = new Node(6);
    root->left = new Node(3);
    root->left->left = new Node(1);
    root->left->right = new Node(8);
    root->right = new Node(4);
    root->right->right = new Node(9);

    inorder(root);
    cout<<endl;
    recoverTree(root);
    inorder(root);
    return 0;
}