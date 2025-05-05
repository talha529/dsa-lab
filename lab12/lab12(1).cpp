#include <iostream>
using namespace std;

struct Node {
    int key, height;
    Node* left;
    Node* right;
    Node(int val) : key(val), height(1), left(NULL), right(NULL) {}
};

int height(Node* n) {
    return n ? n->height : 0;
}

int balance(Node* n) {
    return n ? height(n->left) - height(n->right) : 0;
}

Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));
    return x;
}

Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));
    return y;
}

Node* insertAVL(Node* node, int key) {
    if (!node) return new Node(key);
    if (key < node->key) node->left = insertAVL(node->left, key);
    else if (key > node->key) node->right = insertAVL(node->right, key);
    else return node;

    node->height = 1 + max(height(node->left), height(node->right));
    int b = balance(node);

    if (b > 1 && key < node->left->key) return rotateRight(node);
    if (b < -1 && key > node->right->key) return rotateLeft(node);
    if (b > 1 && key > node->left->key) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    if (b < -1 && key < node->right->key) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;
    root = insertAVL(root, 50);
    insertAVL(root, 30);
    insertAVL(root, 70);
    insertAVL(root, 20);
    insertAVL(root, 40);
    insertAVL(root, 60);
    insertAVL(root, 80);
    inorder(root);
    return 0;
}

