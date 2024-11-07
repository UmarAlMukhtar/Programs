//SORTING
#include <stdio.h> 
 
void selectionSort(int arr[], int n) { 
    for (int i = 0; i < n - 1; i++) { 
        int minIndex = i; 
        for (int j = i + 1; j < n; j++) 
            if (arr[j] < arr[minIndex]) 
                minIndex = j; 
        // Swap the found minimum element with the first element 
        int temp = arr[minIndex]; 
        arr[minIndex] = arr[i]; 
        arr[i] = temp; 
    } 
} 
 
void bubbleSort(int arr[], int n) { 
    for (int i = 0; i < n - 1; i++) { 
        for (int j = 0; j < n - i - 1; j++) 
            if (arr[j] > arr[j + 1]) { 
                // Swap arr[j] and arr[j+1] 
                int temp = arr[j]; 
                arr[j] = arr[j + 1]; 
                arr[j + 1] = temp; 
            } 
    } 
} 
 
void insertionSort(int arr[], int n) { 
    for (int i = 1; i < n; i++) { 
        int key = arr[i]; 
        int j = i - 1; 
        // Move elements of arr[0..i-1], that are greater than key, 
        // to one position ahead of their current position 
        while (j >= 0 && arr[j] > key) { 
            arr[j + 1] = arr[j]; 
            j--; 
        } 
        arr[j + 1] = key; 
    } 
} 
 
void printArray(int arr[], int size) { 
    for (int i = 0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 
 
int main() { 
    int arr[100], n, choice; 
 
    printf("Enter number of elements: "); 
    scanf("%d", &n); 
    printf("Enter the elements:\n"); 
    for (int i = 0; i < n; i++) 
        scanf("%d", &arr[i]); 
 
    while (1) { 
        printf("\nMenu:\n1. Selection Sort\n2. Bubble Sort\n3. Insertion Sort\n4. 
Exit\nEnter your choice: "); 
        scanf("%d", &choice); 
 
        switch (choice) { 
            case 1: 
                selectionSort(arr, n); 
                printf("Sorted array (Selection Sort): "); 
                printArray(arr, n); 
                break; 
            case 2: 
                bubbleSort(arr, n); 
                printf("Sorted array (Bubble Sort): "); 
                printArray(arr, n); 
                break; 
            case 3: 
                insertionSort(arr, n); 
                printf("Sorted array (Insertion Sort): "); 
                printArray(arr, n); 
                break; 
            case 4: 
                printf("Exiting...\n"); 
                return 0; 
            default: 
                printf("Invalid choice. Please try again.\n"); 
        } 
    } 
} 
