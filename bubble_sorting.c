#include <stdio.h>

// Function to perform an optimized bubble sort
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    int swapped;
    
    // Outer loop for each pass
    for (i = 0; i < n - 1; i++) {
        swapped = 0; // Reset flag for the current pass
        
        // Inner loop to compare adjacent elements
        for (j = 0; j < n - i - 1; j++) {
            // Swap if the current element is greater than the next
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1; // Mark that a swap occurred
            }
        }
        
        // If no elements were swapped, the array is already sorted
        if (swapped == 0) {
            break;
        }
    }
}

// Function to print the array elements
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int data[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(data) / sizeof(data[0]);
    
    printf("Unsorted Array:\n");
    printArray(data, size);
    
    bubbleSort(data, size);
    
    printf("Sorted Array in Ascending Order:\n");
    printArray(data, size);
    
    return 0;
}