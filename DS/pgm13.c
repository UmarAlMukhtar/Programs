//BINARY TREE TRAVERSAL

#include <stdio.h> 
#include <stdlib.h> 
 
struct Node { 
    int data; 
    struct Node* left; 
    struct Node* right; 
}; 
 
struct Node* createNode(int data) { 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
    newNode->data = data; 
    newNode->left = newNode->right = NULL; 
    return newNode; 
} 
 
void inorder(struct Node* root) { 
    if (root != NULL) { 
        inorder(root->left); 
        printf("%d ", root->data); 
        inorder(root->right); 
    } 
} 
 
void preorder(struct Node* root) { 
    if (root != NULL) { 
        printf("%d ", root->data); 
        preorder(root->left); 
        preorder(root->right); 
    } 
} 
 
void postorder(struct Node* root) { 
    if (root != NULL) { 
        postorder(root->left); 
        postorder(root->right); 
        printf("%d ", root->data); 
    } 
} 
 
int main() { 
    struct Node* root = NULL; 
    int data, choice, n; 
 
    printf("Enter the number of nodes in the binary tree: "); 
    scanf("%d", &n); 
     
    for (int i = 0; i < n; i++) { 
        printf("Enter data for node %d: ", i + 1); 
        scanf("%d", &data); 
        if (root == NULL) { 
            root = createNode(data); // Initialize the root with the first input 
        } else { 
            // Simple insertion logic: left for smaller, right for larger (not a 
balanced BST) 
            struct Node* current = root; 
            struct Node* parent = NULL; 
            while (1) { 
                parent = current; 
                if (data < current->data) { 
                    current = current->left; 
                    if (current == NULL) { 
                        parent->left = createNode(data); 
                        break; 
                    } 
                } else { 
                    current = current->right; 
                    if (current == NULL) { 
                        parent->right = createNode(data); 
                        break; 
                    } 
                } 
            } 
        } 
    } 
 
    while (1) { 
        printf("\nMenu:\n1. Inorder Traversal\n2. Preorder Traversal\n3. 
Postorder Traversal\n4. Exit\nEnter your choice: "); 
        scanf("%d", &choice); 
 
        switch (choice) { 
            case 1: 
                printf("Inorder Traversal: "); 
                inorder(root); 
                printf("\n"); 
                break; 
            case 2: 
                printf("Preorder Traversal: "); 
                preorder(root); 
                printf("\n"); 
                break; 
            case 3: 
                printf("Postorder Traversal: "); 
                postorder(root); 
                printf("\n"); 
                break; 
            case 4: 
                printf("Exiting...\n"); 
                exit(0); 
            default: 
                printf("Invalid choice. Please try again.\n"); 
        } 
    } 
    return 0; 
}
