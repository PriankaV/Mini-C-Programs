#include <stdio.h>

//Bubnle Sort function
void bubble_sort(int array[], int n, int *min, int *max) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (array[j] > array[j+1]) {
                // Swap
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    //Assigning min/max values
    *min = array[0];
    *max = array[n-1];
}

int main() {
    int array[10];
    int i, min, max;

    //Input
    printf("Enter 10 integers:\n");
    for (i = 0; i < 10; i++) {
        scanf("%d", &array[i]);
    }

    //Sort & find min/max
    bubble_sort(array, 10, &min, &max);

    //Outputof sorted arrays
    printf("Sorted list:\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    //Output min/max
    printf("Minimum value: %d\n", min);
    printf("Maximum value: %d\n", max);

    return 0;
}

