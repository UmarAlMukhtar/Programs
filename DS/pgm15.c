//MERGE SORT

#include <stdio.h> 
 
void merge(int arr[], int left, int mid, int right) { 
    int i, j, k; 
    int n1 = mid - left + 1; // Size of left subarray 
    int n2 = right - mid;    // Size of right subarray 
 
    // Create temporary arrays 
    int L[n1], R[n2]; 
 
    // Copy data to temporary arrays L[] and R[] 
    for (i = 0; i < n1; i++) 
        L[i] = arr[left + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[mid + 1 + j]; 
 
    // Merge the temporary arrays back into arr[left..right] 
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = left; // Initial index of merged subarray 
 
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } else { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
 
    // Copy the remaining elements of L[], if there are any 
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
 
    // Copy the remaining elements of R[], if there are any 
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
 
void mergeSort(int arr[], int left, int right) { 
    if (left < right) { 
        // Find the middle point 
        int mid = left + (right - left) / 2; 
 
        // Sort first and second halves 
        mergeSort(arr, left, mid); 
        mergeSort(arr, mid + 1, right); 
 
        // Merge the sorted halves 
        merge(arr, left, mid, right); 
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
 
    mergeSort(arr, 0, n - 1); 
    printf("Sorted array: "); 
    printArray(arr, n); 
 
    return 0; 
} 
