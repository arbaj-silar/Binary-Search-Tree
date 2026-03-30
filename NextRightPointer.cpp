#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node* next;

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

void inorderNext(Node* root) {
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

Node* connect(Node* root) {
    if(root == NULL || root->left == NULL) return root;
    queue<Node*> q;

    q.push(root);
    q.push(NULL);

    Node* pre = NULL;
    while(q.size()>0) {
        Node* curr = q.front();
        q.pop();

        if(curr == NULL) {
            if(q.size() == 0) {
                break;
            }

            q.push(NULL);
        } else {
            if(curr->left != NULL) {
                q.push(curr->left);
            } 
            if(curr->right != NULL) {
                q.push(curr->right);
            }

            if(pre != NULL) {
                pre->next = curr;
            }
        }
        pre = curr;
    }
    return root;
}
int main() {
    vector<int> arr = {3, 2, 1, 5, 6, 4};

    Node* root = buildBST(arr);
    inorder(root);
    cout<<endl;
    Node* ans = connect(root);
    cout<<ans->data<<endl;
    cout<<ans->left->data<<" ";
    cout<<ans->left->next->data<<" ";
    return 0;
}