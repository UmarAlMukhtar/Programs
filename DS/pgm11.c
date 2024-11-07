//QUEUE USING LINKED LIST

#include <stdio.h> 
#include <stdlib.h> 
 
struct Node { 
    int data; 
    struct Node* next; 
}; 
 
void enqueue(struct Node** rear, int data) { 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
    newNode->data = data; 
    if (*rear == NULL) { 
        newNode->next = newNode; 
        *rear = newNode; 
    } else { 
        newNode->next = (*rear)->next; 
        (*rear)->next = newNode; 
        *rear = newNode; 
    } 
    printf("Enqueued %d into the queue.\n", data); 
} 
 
void dequeue(struct Node** rear) { 
    if (*rear == NULL) { 
        printf("Queue Underflow\n"); 
        return; 
    } 
    struct Node* temp = (*rear)->next; 
    if (*rear == temp) { 
        *rear = NULL; 
    } else { 
        (*rear)->next = temp->next; 
    } 
    printf("Dequeued %d from the queue.\n", temp->data); 
    free(temp); 
} 
 
void displayQueue(struct Node* rear) { 
    if (rear == NULL) { 
        printf("Queue is empty.\n"); 
        return; 
    } 
    struct Node* temp = rear->next; 
    printf("Queue contents: "); 
    do { 
        printf("%d -> ", temp->data); 
        temp = temp->next; 
    } while (temp != rear->next); 
    printf("(rear)\n"); 
} 
 
int main() { 
    struct Node* rear = NULL; 
    int choice, data; 
 
    do { 
        printf("\nMenu:\n"); 
        printf("1. Enqueue\n"); 
        printf("2. Dequeue\n"); 
        printf("3. Display queue\n"); 
        printf("4. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
 
        switch (choice) { 
            case 1: 
                printf("Enter data to enqueue: "); 
                scanf("%d", &data); 
                enqueue(&rear, data); 
                break; 
            case 2: 
                dequeue(&rear); 
                break; 
            case 3: 
                displayQueue(rear); 
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
