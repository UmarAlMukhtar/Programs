//QUICK SORT
#include <stdio.h> 
 
void swap(int* a, int* b) { 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 
 
int partition(int arr[], int low, int high) { 
    int pivot = arr[high]; // Pivot element 
    int i = (low - 1); // Index of smaller element 
 
    for (int j = low; j < high; j++) { 
        // If current element is smaller than or equal to pivot 
        if (arr[j] <= pivot) { 
            i++; // Increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); // Return the partitioning index 
} 
 
void quickSort(int arr[], int low, int high) { 
    if (low < high) { 
        // Partitioning index 
        int pi = partition(arr, low, high); 
 
        // Recursively sort elements before and after partition 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 
 
void printArray(int arr[], int size) { 
    for (int i = 0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 
 
int main() { 
    int arr[100], n; 
 
    printf("Enter number of elements: "); 
    scanf("%d", &n); 
    printf("Enter the elements:\n"); 
    for (int i = 0; i < n; i++) 
        scanf("%d", &arr[i]); 
 
    quickSort(arr, 0, n - 1); 
    printf("Sorted array: "); 
    printArray(arr, n); 
    return 0; 
}
