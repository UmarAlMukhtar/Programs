//POLYNOMIAL USING LINKED LIST

#include <stdio.h> 
#include <stdlib.h> 
 
struct Node { 
    int coeff; 
    int exp; 
    struct Node* next; 
}; 
 
void insertTerm(struct Node** poly, int coeff, int exp) { 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
    newNode->coeff = coeff; 
    newNode->exp = exp; 
    newNode->next = NULL; 
 
    if (*poly == NULL || (*poly)->exp < exp) { 
        newNode->next = *poly; 
        *poly = newNode; 
    } else { 
        struct Node* temp = *poly; 
        while (temp->next != NULL && temp->next->exp > exp) 
            temp = temp->next; 
        newNode->next = temp->next; 
        temp->next = newNode; 
    } 
} 
 
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) { 
    struct Node* result = NULL; 
    while (poly1 != NULL && poly2 != NULL) { 
        if (poly1->exp > poly2->exp) { 
            insertTerm(&result, poly1->coeff, poly1->exp); 
            poly1 = poly1->next; 
        } else if (poly1->exp < poly2->exp) { 
            insertTerm(&result, poly2->coeff, poly2->exp); 
            poly2 = poly2->next; 
        } else { 
            int sum = poly1->coeff + poly2->coeff; 
            if (sum != 0) insertTerm(&result, sum, poly1->exp); 
            poly1 = poly1->next; 
            poly2 = poly2->next; 
        } 
    } 
    while (poly1 != NULL) { 
        insertTerm(&result, poly1->coeff, poly1->exp); 
        poly1 = poly1->next; 
    } 
    while (poly2 != NULL) { 
        insertTerm(&result, poly2->coeff, poly2->exp); 
        poly2 = poly2->next; 
    } 
    return result; 
} 
 
struct Node* multiplyPolynomials(struct Node* poly1, struct Node* poly2) { 
    struct Node* result = NULL; 
    for (struct Node* p1 = poly1; p1 != NULL; p1 = p1->next) { 
        for (struct Node* p2 = poly2; p2 != NULL; p2 = p2->next) { 
            int coeff = p1->coeff * p2->coeff; 
            int exp = p1->exp + p2->exp; 
            struct Node* temp = result; 
            while (temp != NULL && temp->exp != exp) temp = temp->next; 
            if (temp != NULL) { 
                temp->coeff += coeff; 
            } else { 
                insertTerm(&result, coeff, exp); 
            } 
        } 
    } 
    return result; 
} 
 
void displayPolynomial(struct Node* poly) { 
    while (poly != NULL) { 
        printf("%dx^%d", poly->coeff, poly->exp); 
        poly = poly->next; 
        if (poly != NULL) printf(" + "); 
    } 
    printf("\n"); 
} 
 
int main() { 
    struct Node* poly1 = NULL; 
    struct Node* poly2 = NULL; 
    struct Node* result = NULL; 
    int choice, coeff, exp, terms; 
 
    printf("Enter number of terms in the first polynomial: "); 
    scanf("%d", &terms); 
    for (int i = 0; i < terms; i++) { 
        printf("Enter coefficient and exponent: "); 
        scanf("%d %d", &coeff, &exp); 
        insertTerm(&poly1, coeff, exp); 
    } 
 
    printf("Enter number of terms in the second polynomial: "); 
    scanf("%d", &terms); 
    for (int i = 0; i < terms; i++) { 
        printf("Enter coefficient and exponent: "); 
        scanf("%d %d", &coeff, &exp); 
        insertTerm(&poly2, coeff, exp); 
    } 
 
    do { 
        printf("\nMenu:\n"); 
        printf("1. Add Polynomials\n"); 
        printf("2. Multiply Polynomials\n"); 
        printf("3. Display Polynomial 1\n"); 
        printf("4. Display Polynomial 2\n"); 
        printf("5. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
 
        switch (choice) { 
            case 1: 
                result = addPolynomials(poly1, poly2); 
                printf("Result of addition: "); 
                displayPolynomial(result); 
                break; 
            case 2: 
                result = multiplyPolynomials(poly1, poly2); 
                printf("Result of multiplication: "); 
                displayPolynomial(result); 
                break; 
            case 3: 
                printf("Polynomial 1: "); 
                displayPolynomial(poly1); 
                break; 
            case 4: 
                printf("Polynomial 2: "); 
                displayPolynomial(poly2); 
                break; 
            case 5: 
                printf("Exiting...\n"); 
                break; 
            default: 
                printf("Invalid choice! Try again.\n"); 
        } 
    } while (choice != 5); 
 
    return 0; 
} 
