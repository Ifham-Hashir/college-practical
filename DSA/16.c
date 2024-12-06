#include <stdio.h>
#include <stdlib.h>

// Define the structure for a binary tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node with given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to perform inorder traversal (left, root, right)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);       // Traverse left subtree
        printf("%d ", root->data); // Print root
        inorder(root->right);      // Traverse right subtree
    }
}

// Function to perform preorder traversal (root, left, right)
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data); // Print root
        preorder(root->left);      // Traverse left subtree
        preorder(root->right);     // Traverse right subtree
    }
}

// Function to perform postorder traversal (left, right, root)
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);     // Traverse left subtree
        postorder(root->right);    // Traverse right subtree
        printf("%d ", root->data); // Print root
    }
}

int main() {
    struct Node *root, *leftChild, *rightChild;

    // Create the root node
    root = createNode(1);
    leftChild = createNode(2);
    rightChild = createNode(3);

    // Link the nodes to form the binary tree
    root->left = leftChild;
    root->right = rightChild;

    // Further create child nodes
    leftChild->left = createNode(4);
    leftChild->right = createNode(5);
    rightChild->left = createNode(6);
    rightChild->right = createNode(7);

    // Display the tree using different traversals
    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    printf("Preorder Traversal: ");
    preorder(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorder(root);
    printf("\n");

    return 0;
}
