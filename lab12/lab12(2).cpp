#include <iostream>
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

void dfsTree(TreeNode* root) {
    if (root == NULL) return;
    cout << root->val << " ";
    dfsTree(root->left);
    dfsTree(root->right);
}

int main() {
    TreeNode* root = NULL;
    root = insertTree(root, 50);
    insertTree(root, 30);
    insertTree(root, 70);
    insertTree(root, 20);
    insertTree(root, 40);
    dfsTree(root);
    return 0;
}

