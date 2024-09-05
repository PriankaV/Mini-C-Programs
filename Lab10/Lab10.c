//file name: awamdeh_faris_string_reversal.c

#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

void reverseString(char *str);
void swap(char *left, char *right);

int main() {
    char input[MAX_LENGTH];

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    // Remove newline character if present
    input[strcspn(input, "\n")] = '\0';

    reverseString(input);

    printf("Orginal string: %s\n", input);
    printf("Reversed string: %s\n", input);

    return 0;
}

void reverseString(char *str) {
    int length = strlen(str);
    char *start = str;
    char *end = str + length - 1;

    while (start < end) {
        swap(start, end);
        start++;
        end--;
    }
}

void swap(char *left, char *right) {
    char temp = *left;
    *left = *right;
    *right = temp;
}
