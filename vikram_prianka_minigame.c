/*
Name: Prianka Vikram - Homework 2
Description: This program implements a mini-game where the user tries to guess a secret code, by generating a random code.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TRIES 8   //Max amount of Tries
#define DIGIT_COUNT 3  //Secret Code Length
#define MAX_DIGIT 10   //Max value in Secret Code [0-9]

//Function prototypes
void generateSecretCode(int code[]);
void checkGuess(int secretCode[], int guess[]);

int main() {
    int secretCode[DIGIT_COUNT]; //Array to store the secret code
    generateSecretCode(secretCode); //Generating the secret code

    //Print Introduction
    printf("Welcome to the Code Guessing Game!\n");
    printf("You have %d tries to guess the secret code, which consists of %d digits.\n", MAX_TRIES, DIGIT_COUNT);

    //Main game loop
    for (int triesLeft = MAX_TRIES; triesLeft > 0; triesLeft--) {
        int guess[DIGIT_COUNT]; // Array to store the user's guess
        printf("\n%d tries remaining, Enter your guess (it's a %d-digit number): ", triesLeft, DIGIT_COUNT);

        // Read user input
        if (scanf("%1d%1d%1d", &guess[0], &guess[1], &guess[2]) != DIGIT_COUNT) {
            printf("Invalid input, please enter a %d-digit code.\n", DIGIT_COUNT);
            while (getchar() != '\n'); //Clear input buffer
            continue; //Restart the loop to get another guess
        }

        //Check user's guess
        checkGuess(secretCode, guess);

        //Check if guess is correct
        if (secretCode[0] == guess[0] && secretCode[1] == guess[1] && secretCode[2] == guess[2]) {
            printf("Congratulations! You guessed the secret code!\n");
            return 0;
        }
    }

    //If the loop ends, the user failed to guess the code
    printf("\nSorry, you've run out of tries, the secret code was: %d%d%d\n", secretCode[0], secretCode[1], secretCode[2]);
    printf("Game over D:.\n");

    return 0;
}

//Function to generate the secret code
void generateSecretCode(int code[]) {
    srand(time(NULL)); //Seed the random number generator
    for (int i = 0; i < DIGIT_COUNT; i++) {
        code[i] = rand() % MAX_DIGIT; //Generate random digits and store them in the code array
    }
}

//Function to check the user's guess against the secret code and provide feedback
void checkGuess(int secretCode[], int guess[]) {
    int correctPlace = 0; //Count of digits that are correct and in the right index
    int correctDigit = 0; //Count of digits that are correct but in the wrong index

    //Check each digit in the guess
    for (int i = 0; i < DIGIT_COUNT; i++) {
        if (secretCode[i] == guess[i]) {
            correctPlace++; //Increment correctPlace if the digit is correct & in the right index
        } else {
            //Check if the digit exists in the secret code
            for (int j = 0; j < DIGIT_COUNT; j++) {
                if (secretCode[j] == guess[i]) {
                    correctDigit++; //Increment correctDigit if the digit is correct but in the wrong index
                    break;
                }
            }
        }
    }
    //Print feedback to the user
    printf("Feedback: %d digit(s) are correct and in the right place, %d digit(s) are correct but not in the right place.\n", correctPlace, correctDigit);


    //Check to see if the guess is higher or lower than the secret code
    if (secretCode[0] > guess[0] || secretCode[1] > guess[1] || secretCode[2] > guess[2]) {
        printf("Feedback: The secret code is higher than your guess.\n");
    } else if (secretCode[0] < guess[0] || secretCode[1] < guess[1] || secretCode[2] < guess[2]) {
        printf("Feedback: The secret code is lower than your guess.\n");
    }
}