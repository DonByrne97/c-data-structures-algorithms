#include <stdio.h>
#include <stdlib.h>

void swap(int* xp, int* yp) {
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
}

void selection_sort(int array[], int size) {
    for(int i = 0; i < size - 1; i++) {
        int min_idx = i; 
        for(int j = i + 1; j < size; j++) {
            if(array[j] < array[min_idx]) {
                min_idx = j; 
            }
        }
        swap(&array[min_idx], &array[i]); // Does nothing unless min_idx is set to j, meaning we've encountered a value lower than the current value of min_idx
    }
}

void print_array(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]); 
    }
    printf("\n"); 
}

int main() {
    int array[] = {12, 51, 87, 3, 6, 92, 25, 10, 11, 55, 30}; 
    int size = sizeof(array) / sizeof(array[0]); 
    selection_sort(array, size); 
    print_array(array, size); 
}

// Time Complexity: O(n^2)
// Space Complexity: O(1) 
