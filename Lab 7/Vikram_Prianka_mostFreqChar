#include <stdio.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

int main() {
    FILE *file = fopen("sample.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int frequency[ALPHABET_SIZE] = {0};

    int c;
    while ((c = fgetc(file)) != EOF) {
        if (isalpha(c)) {
            c = tolower(c); // Convert to lowercase for case insensitivity
            frequency[c - 'a']++;
        }
    }

    fclose(file);

    int maxFrequency = 0;
    char mostFrequentChar;

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (frequency[i] > maxFrequency) {
            maxFrequency = frequency[i];
            mostFrequentChar = 'a' + i;
        }
    }

    printf("Most frequent character: %c\n", mostFrequentChar);
    printf("Number of appearances: %d\n", maxFrequency);

    return 0;
}
