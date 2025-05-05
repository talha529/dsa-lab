#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* insertTree(TreeNode* root, int val) {
    if (root == NULL) return new TreeNode(val);
    if (val < root->val) root->left = insertTree(root->left, val);
    else root->right = insertTree(root->right, val);
    return root;
}

void bfsTree(TreeNode* root) {
    if (root == NULL) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();
        cout << curr->val << " ";
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
}

int main() {
    TreeNode* root = NULL;
    root = insertTree(root, 50);
    insertTree(root, 30);
    insertTree(root, 70);
    insertTree(root, 20);
    insertTree(root, 40);
    bfsTree(root);
    return 0;
} 
