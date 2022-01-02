#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int data) {
        this->data = data;
        left = right = NULL;    
    }
};


void inOrder(struct TreeNode *root) {
    stack<TreeNode *> s;
    TreeNode * curr = root;
    while(curr != NULL || s.empty() == false) {
        while(curr != NULL) {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
}

void preOrder(struct TreeNode *root) {

}

void postOrder(struct TreeNode *root) {
    
}

int main() {
    struct TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    inOrder(root);
    return 0;
}