//STACK USING LINKED LIST
#include <stdio.h> 
#include <stdlib.h> 
 
struct Node { 
    int data; 
    struct Node* next; 
}; 
 
void push(struct Node** top, int data) { 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
    newNode->data = data; 
    newNode->next = *top; 
    *top = newNode; 
    printf("Pushed %d onto the stack.\n", data); 
} 
 
void pop(struct Node** top) { 
    if (*top == NULL) { 
        printf("Stack Underflow\n"); 
        return; 
    } 
    struct Node* temp = *top; 
    printf("Popped %d from the stack.\n", temp->data); 
    *top = (*top)->next; 
    free(temp); 
} 
 
void displayStack(struct Node* top) { 
    if (top == NULL) { 
        printf("Stack is empty.\n"); 
        return; 
    } 
    struct Node* temp = top; 
    printf("Stack contents: "); 
    while (temp != NULL) { 
        printf("%d -> ", temp->data); 
        temp = temp->next; 
    } 
    printf("NULL\n"); 
} 
 
int main() { 
    struct Node* top = NULL; 
    int choice, data; 
 
    do { 
        printf("\nMenu:\n"); 
        printf("1. Push\n"); 
        printf("2. Pop\n"); 
        printf("3. Display stack\n"); 
        printf("4. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
 
        switch (choice) { 
            case 1: 
                printf("Enter data to push onto the stack: "); 
                scanf("%d", &data); 
                push(&top, data); 
                break; 
            case 2: 
                pop(&top); 
                break; 
            case 3: 
                displayStack(top); 
                break; 
            case 4: 
                printf("Exiting...\n"); 
                break; 
            default: 
                printf("Invalid choice! Try again.\n"); 
        } 
    } while (choice != 4); 
 
    return 0; 
}
