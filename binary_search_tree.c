#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node in BST
struct Node* insert(struct Node* node, int data) {
    if (node == NULL) {
        return createNode(data);
    }

    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    }

    return node;
}

// Function to perform inorder traversal
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Function to perform preorder traversal
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Function to perform postorder traversal
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Function to search a key in BST
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }

    if (key < root->data) {
        return search(root->left, key);
    }

    return search(root->right, key);
}

// Main function
int main() {
    struct Node* root = NULL;
    int choice, key,n;
    printf("enter the no. of element to be insert\n");
    scanf("%d",&n);
    // int arr[] = {6, 9, 5, 2, 8, 15, 24, 14, 7, 8, 5, 2};
    int arr[100];
    printf("enter the element to be insert\n");
    for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
    }
    // int n = sizeof(arr) / sizeof(arr[0]);

    do {
        printf("\nMenu:\n");
        printf("1. Create BST\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Search for a key\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Creating BST
                for (int i = 0; i < n; i++) {
                    root = insert(root, arr[i]);
                }
                printf("BST created successfully.\n");
                break;

            case 2:
                // Inorder traversal
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 3:
                // Preorder traversal
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;

            case 4:
                // Postorder traversal
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;

            case 5:
                // Searching for a key
                printf("Enter the key to search: ");
                scanf("%d", &key);
                struct Node* found = search(root, key);
                if (found != NULL) {
                    printf("Key %d found in the BST.\n", key);
                } else {
                    printf("Key %d not found in the BST.\n", key);
                }
                break;

            case 6:
                // Exit
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}
