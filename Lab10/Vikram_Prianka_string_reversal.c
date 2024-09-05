#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

// Function prototypes
void reverseString(char *str);
void swap(char *left, char *right);

int main() {
    char input[MAX_LENGTH];
    char original[MAX_LENGTH]; // To store the original string

    printf("Enter a string: ");

    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = '\0';

    // Copy the original string
    strcpy(original, input);

    // Reverse the string
    reverseString(input);

    printf("Original string: %s\n", original); // Print the original string
    printf("Reversed string: %s\n", input);

    return 0;
}

// Function to reverse the given string
void reverseString(char *str) {
    int length = strlen(str);
    char *start = str;
    char *end = str + length - 1;

    // Swap characters from the beginning and end, towards the middle
    while (start < end) {
        swap(start, end);
        start++;
        end--;
    }
}

// Function to swap two characters
void swap(char *left, char *right) {
    char temp = *left;
    *left = *right;
    *right = temp;
}
