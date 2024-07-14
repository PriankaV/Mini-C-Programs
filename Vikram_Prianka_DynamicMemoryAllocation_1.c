#include <stdio.h>
#include <stdlib.h>

#define SIZE 10 

typedef struct {
    char title[100];
    char author[100];
    int num_pages;
    float price;
} Book;

int main() {
    Book *books;

    //Dynamically allocate memory for the array of Book structures
    books = (Book *)malloc(SIZE * sizeof(Book));

    //Check if memory allocation was successful
    if (books == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1; // Exit the program with an error code
    }

    //Free the allocated memory when it's no longer needed
    free(books);

    return 0;
}
