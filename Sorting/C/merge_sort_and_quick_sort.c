#include <stdio.h>
#include <stdlib.h>

// Function to merge two subarrays for Merge Sort
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    // Temporary arrays to hold the subarrays
    int L[n1], R[n2];

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[m + 1 + i];

    // Merge the temporary arrays back into the original array
    int i = 0, j = 0, k = l;
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

    // Copy any remaining elements from L[]
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy any remaining elements from R[]
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Merge Sort function
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        // Recursively sort the first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Merge the sorted halves
        merge(arr, l, m, r);
    }
}

// Function to partition the array for Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Pivot element
    int i = (low - 1);  // Index of smaller element

    // Rearrange the array based on the pivot
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Swap pivot to the correct position
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return (i + 1);  // Return the pivot index
}

// Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Find the partition index
        int pi = partition(arr, low, high);

        // Recursively sort the elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;

    // Input for the array size
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    
    // Input for array elements
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Copy the original array for both sorting algorithms
    int arrMerge[n], arrQuick[n];
    for (int i = 0; i < n; i++) {
        arrMerge[i] = arr[i];
        arrQuick[i] = arr[i];
    }

    // Apply Merge Sort
    printf("\nArray before Merge Sort: ");
    printArray(arrMerge, n);

    mergeSort(arrMerge, 0, n - 1);

    printf("Array after Merge Sort: ");
    printArray(arrMerge, n);

    // Apply Quick Sort
    printf("\nArray before Quick Sort: ");
    printArray(arrQuick, n);

    quickSort(arrQuick, 0, n - 1);

    printf("Array after Quick Sort: ");
    printArray(arrQuick, n);

    return 0;
}
