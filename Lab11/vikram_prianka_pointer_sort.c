#include <stdio.h>

//Function to perform Bubble Sort on an array using pointers
void bubbleSort(int *arr, int n) {
    int *ptr1, *ptr2, temp;
    
    //Outer loop for passes
    for (ptr1 = arr; ptr1 < arr + n - 1; ptr1++) {
        //Inner loop for comparisons
        for (ptr2 = arr; ptr2 < arr + n - 1 - (ptr1 - arr); ptr2++) {
            //Swap if the current element is greater than the next element
            if (*ptr2 > *(ptr2 + 1)) {
                temp = *ptr2;
                *ptr2 = *(ptr2 + 1);
                *(ptr2 + 1) = temp;
            }
        }
    }
}

//Function to print the elements of an array
void printArray(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    //Declare an array of size 'n'
    int arr[n];
    
    //Input array elements from the user
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    //Print original array
    printf("Original array: ");
    printArray(arr, n);
    
    //Sort the array using Bubble Sort
    bubbleSort(arr, n);
    
    //Print sorted array
    printf("Sorted array: ");
    printArray(arr, n);
    
    //Print largest and smallest numbers
    printf("Largest number: %d\n", arr[n - 1]);
    printf("Smallest number: %d\n", arr[0]);
    
    return 0;
}
