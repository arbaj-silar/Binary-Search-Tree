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

Node* buildBSTFromSorted(vector<int>& arr, int st, int end) {
    if(st>end) return NULL;

    int mid = st + (end-st)/2;
    Node* root = new Node(arr[mid]);

    root->left = buildBSTFromSorted(arr, st, mid-1);
    root->right = buildBSTFromSorted(arr, mid+1, end);
    return root;
}

void inorder(Node* root, vector<int>& arr) {
    if(root == NULL) return;
    
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}

Node* buildBST(vector<int>& arr) {
    Node* root = NULL;
    
    for(int val: arr) {
        root = insert(root, val);
    }
    return root;
}

Node* mergeBST(Node* r1, Node* r2) {
    vector<int> a, b;
    inorder(r1, a);
    inorder(r2, b);

    vector<int> temp;
    int i=0, j=0;
    while(i<a.size() && j<b.size()) {
        if(a[i]>b[j]) {
            temp.push_back(b[j++]);
        } else {
            temp.push_back(a[i++]);
        }
    }
    while(j<b.size()) {
        temp.push_back(b[j++]);
    }
    while(i<a.size()) {
        temp.push_back(a[i++]);
    }

    return buildBSTFromSorted(temp, 0, temp.size()-1);
}

int main() {
    vector<int> a = {8, 2, 1, 10};
    vector<int> b = {5, 3, 0};

    Node* r1 = buildBST(a);
    Node* r2 = buildBST(b);
    
    Node* root = mergeBST(r1, r2);
    vector<int> ans;
    inorder(root, ans);
    for(int a: ans) {
        cout<<a<<" ";
    }
    cout<<endl;
    return 0;
}