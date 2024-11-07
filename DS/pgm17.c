//BINARY SEARCH

#include <stdio.h> 
 
int binarySearchIterative(int arr[], int n, int target) { 
    int low = 0, high = n - 1; 
 
    while (low <= high) { 
        int mid = low + (high - low) / 2; 
 
        if (arr[mid] == target) 
            return mid; // Target found 
        else if (arr[mid] < target) 
            low = mid + 1; // Search in the right half 
        else 
            high = mid - 1; // Search in the left half 
    } 
    return -1; // Target not found 
} 
 
int binarySearchRecursive(int arr[], int low, int high, int target) { 
    if (low > high) 
        return -1; // Target not found 
 
    int mid = low + (high - low) / 2; 
 
    if (arr[mid] == target) 
        return mid; // Target found 
    else if (arr[mid] < target) 
        return binarySearchRecursive(arr, mid + 1, high, target); // Search in 
the right half 
    else 
        return binarySearchRecursive(arr, low, mid - 1, target); // Search in the 
left half 
} 
 
int main() { 
    int arr[100], n, target, result; 
 
    printf("Enter number of elements: "); 
    scanf("%d", &n); 
    printf("Enter the sorted elements:\n"); 
    for (int i = 0; i < n; i++) 
        scanf("%d", &arr[i]); 
 
    printf("Enter the target value to search: "); 
    scanf("%d", &target); 
 
    // Perform iterative binary search 
    result = binarySearchIterative(arr, n, target); 
    if (result != -1) 
        printf("Iterative: Target %d found at index %d\n", target, result); 
    else 
        printf("Iterative: Target %d not found in the array\n", target); 
 
    // Perform recursive binary search 
result = binarySearchRecursive(arr, 0, n - 1, target); 
if (result != -1) 
printf("Recursive: Target %d found at index %d\n", target, result); 
else 
printf("Recursive: Target %d not found in the array\n", target); 
return 0; 
} 
