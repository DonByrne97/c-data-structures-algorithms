#include <stdio.h>
#include <stdlib.h> 
 
void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void bubble_sort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void print_array(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]); 
    }
    printf("\n"); 
}

int main() 
{
    int array[] = {1, 6, 3, 9, 12, 2, 85, 34, 56}; 
    int size = sizeof(array)/sizeof(array[0]); 
    printf("Unsorted: \n"); 
    print_array(array, size); 
    printf("Sorted: \n"); 
    bubble_sort(array, size); 
    print_array(array, size); 
}
