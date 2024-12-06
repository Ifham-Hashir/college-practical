#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data, height;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

int height(struct Node* node) {
    return node ? node->height : 0;
}

int getBalance(struct Node* node) {
    return node ? height(node->left) - height(node->right) : 0;
}

struct Node* rotateRight(struct Node* y) {
    struct Node* x = y->left, * T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));
    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));
    return x;
}

struct Node* rotateLeft(struct Node* x) {
    struct Node* y = x->right, * T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));
    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));
    return y;
}

struct Node* insert(struct Node* root, int data) {
    if (!root) return createNode(data);
    if (data < root->data) root->left = insert(root->left, data);
    else if (data > root->data) root->right = insert(root->right, data);
    else return root;

    root->height = 1 + (height(root->left) > height(root->right) ? height(root->left) : height(root->right));
    
    int balance = getBalance(root);

    if (balance > 1 && data < root->left->data) return rotateRight(root);
    if (balance < -1 && data > root->right->data) return rotateLeft(root);
    if (balance > 1 && data > root->left->data) { root->left = rotateLeft(root->left); return rotateRight(root); }
    if (balance < -1 && data < root->right->data) { root->right = rotateRight(root->right); return rotateLeft(root); }
    
    return root;
}

void inorder(struct Node* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int n, value;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }
    
    printf("Inorder Traversal of AVL Tree: ");
    inorder(root);
    printf("\n");

    return 0;
}

// Enter number of elements: 5
// Enter elements: 11 7 9 10 5
// Inorder Traversal of AVL Tree: 5 7 9 10 11 
