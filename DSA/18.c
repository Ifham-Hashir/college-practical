#include <stdio.h>
#include <stdlib.h>

// Define the structure for a binary tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert a new node into the BST
struct Node* insert(struct Node* root, int data) {
    if (!root) return createNode(data);
    if (data < root->data) root->left = insert(root->left, data);
    else if (data > root->data) root->right = insert(root->right, data);
    return root;
}

// Delete a node from the BST
struct Node* deleteNode(struct Node* root, int data) {
    if (!root) return NULL;
    if (data < root->data) root->left = deleteNode(root->left, data);
    else if (data > root->data) root->right = deleteNode(root->right, data);
    else {
        if (!root->left) return root->right;
        if (!root->right) return root->left;
        struct Node* temp = root->right;
        while (temp && temp->left) temp = temp->left;
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Inorder traversal
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

    // Input for creating BST
    printf("Enter number of elements to insert: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    // Display the BST
    printf("BST Inorder: ");
    inorder(root);
    printf("\n");

    // Insert a node
    printf("Enter a value to insert: ");
    scanf("%d", &value);
    root = insert(root, value);
    printf("BST after insertion: ");
    inorder(root);
    printf("\n");

    // Delete a node
    printf("Enter a value to delete: ");
    scanf("%d", &value);
    root = deleteNode(root, value);
    printf("BST after deletion: ");
    inorder(root);
    printf("\n");

    return 0;
}

// Enter number of elements to insert: 5
// Enter elements: 10 7 9 5 11
// BST Inorder: 5 7 9 10 11 
// Enter a value to insert: 8
// BST after insertion: 5 7 8 9 10 11 
// Enter a value to delete: 7
// BST after deletion: 5 8 9 10 11 