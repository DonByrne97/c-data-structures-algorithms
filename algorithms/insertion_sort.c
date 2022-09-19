#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int array[], int size) {
    for(int i = 1; i < size; i++) {
        int key = array[i]; 
        int j = i - 1; 
        while(key < array[j] && j >= 0) {
            array[j + 1] = array[j]; 
            --j; 
        }
        array[j + 1] = key; 
    }
}

void print_array(int array[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", array[i]); 
    }
    printf("\n"); 
}

int main()
{
    int array[] = {2, 1, 6, 13, 95, 40, 20, 5}; 
    int size = sizeof(array)/sizeof(array[0]); 
    printf("Unsorted Array: \n"); 
    print_array(array, size); 
    printf("Sorted Array: \n");
    insertion_sort(array, size);
    print_array(array, size); 
}
