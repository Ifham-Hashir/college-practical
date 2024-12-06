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
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to create a binary tree
struct Node* createTree() {
    int data;
    scanf("%d", &data);

    if (data == -1) {
        return NULL;
    }

    struct Node* root = createNode(data);
    printf("Enter left child of %d: ", data);
    root->left = createTree();
    printf("Enter right child of %d: ", data);
    root->right = createTree();

    return root;
}

// Function for inorder traversal (left, root, right)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);       // Traverse left subtree
        printf("%d ", root->data); // Print root
        inorder(root->right);      // Traverse right subtree
    }
}

// Function for preorder traversal (root, left, right)
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data); // Print root
        preorder(root->left);      // Traverse left subtree
        preorder(root->right);     // Traverse right subtree
    }
}

// Function for postorder traversal (left, right, root)
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);     // Traverse left subtree
        postorder(root->right);    // Traverse right subtree
        printf("%d ", root->data); // Print root
    }
}

int main() {
    struct Node* root = NULL;

    // Create the binary tree
    printf("Create the binary tree: ");
    root = createTree();

    // Perform and display tree traversals
    printf("\nInorder Traversal: ");
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

// Create the binary tree: 1
// Enter left child of 1: 2
// Enter left child of 2: 4
// Enter left child of 4: -1
// Enter right child of 4: -1
// Enter right child of 2: 5
// Enter left child of 5: -1
// Enter right child of 5: -1
// Enter right child of 1: 3
// Enter left child of 3: -1
// Enter right child of 3: -1

// Inorder Traversal: 4 2 5 1 3 
// Preorder Traversal: 1 2 4 5 3 
// Postorder Traversal: 4 5 2 3 1 