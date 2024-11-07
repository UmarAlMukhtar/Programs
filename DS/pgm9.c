//CIRCULAR SINGLY LINKED LIST
#include <stdio.h> 
#include <stdlib.h> 
 
struct Node { 
    int data; 
    struct Node* next; 
}; 
 
void insertBeginning(struct Node** head, int data) { 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
    newNode->data = data; 
    if (*head == NULL) { 
        newNode->next = newNode; 
        *head = newNode; 
        return; 
    } 
    struct Node* temp = *head; 
    while (temp->next != *head) temp = temp->next; 
    newNode->next = *head; 
    temp->next = newNode; 
    *head = newNode; 
} 
 
void insertEnd(struct Node** head, int data) { 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
    newNode->data = data; 
    if (*head == NULL) { 
        newNode->next = newNode; 
        *head = newNode; 
        return; 
    } 
    struct Node* temp = *head; 
    while (temp->next != *head) temp = temp->next; 
    temp->next = newNode; 
    newNode->next = *head; 
} 
 
void deleteBeginning(struct Node** head) { 
    if (*head == NULL) return; 
    if ((*head)->next == *head) { 
        free(*head); 
        *head = NULL; 
        return; 
    } 
    struct Node* temp = *head; 
    while (temp->next != *head) temp = temp->next; 
    struct Node* toDelete = *head; 
    temp->next = (*head)->next; 
    *head = (*head)->next; 
    free(toDelete); 
} 
 
void deleteEnd(struct Node** head) { 
    if (*head == NULL) return; 
    if ((*head)->next == *head) { 
        free(*head); 
        *head = NULL; 
        return; 
    } 
    struct Node* temp = *head; 
    while (temp->next->next != *head) temp = temp->next; 
    struct Node* toDelete = temp->next; 
    temp->next = *head; 
    free(toDelete); 
} 
 
void displayList(struct Node* head) { 
    if (head == NULL) { 
        printf("List is empty.\n"); 
        return; 
    } 
    struct Node* temp = head; 
    do { 
        printf("%d -> ", temp->data); 
        temp = temp->next; 
    } while (temp != head); 
    printf("(head)\n"); 
} 
 
int main() { 
    struct Node* head = NULL; 
    int choice, data; 
 
    do { 
        printf("\nMenu:\n"); 
        printf("1. Insert at the beginning\n"); 
        printf("2. Insert at the end\n"); 
        printf("3. Delete from beginning\n"); 
        printf("4. Delete from end\n"); 
        printf("5. Display the linked list\n"); 
        printf("6. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
 
        switch (choice) { 
            case 1: 
                printf("Enter data to insert at the beginning: "); 
                scanf("%d", &data); 
                insertBeginning(&head, data); 
                break; 
            case 2: 
                printf("Enter data to insert at the end: "); 
                scanf("%d", &data); 
                insertEnd(&head, data); 
                break; 
            case 3: 
                deleteBeginning(&head); 
                printf("Deleted from beginning.\n"); 
                break; 
            case 4: 
                deleteEnd(&head); 
                printf("Deleted from end.\n"); 
                break; 
            case 5: 
                printf("Circular linked list: "); 
                displayList(head); 
                break; 
            case 6: 
                printf("Exiting...\n"); 
                break; 
            default: 
                printf("Invalid choice! Try again.\n"); 
        } 
    } while (choice != 6); 
 
    return 0; 
} 
