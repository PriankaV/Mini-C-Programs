#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//Function Declarations
double addition(double left, double right);
double subtraction(double left, double right);
double multiplication(double left, double right);
double division(double left, double right);
double power(double base, double exponent);
double floor_division(double left, double right);

int main() {
    double left, right, result;
    char operator[10]; //Operator as a String

    //Input = left val, operator, right val
    printf("Enter left value: ");
    scanf("%lf", &left);

    printf("Enter operator (+, -, *, /, **, //): ");
    scanf("%s", operator);

    printf("Enter right value: ");
    scanf("%lf", &right);

    //Calculation based on the Operator
    if (strcmp(operator, "+") == 0) {
        result = addition(left, right);
    } else if (strcmp(operator, "-") == 0) {
        result = subtraction(left, right);
    } else if (strcmp(operator, "*") == 0) {
        result = multiplication(left, right);
    } else if (strcmp(operator, "/") == 0) {
        result = division(left, right);
    } else if (strcmp(operator, "**") == 0) {
        result = power(left, right);
    } else if (strcmp(operator, "//") == 0) {
        result = floor_division(left, right);
    } else {
        printf("Invalid operator: %s\n", operator);
        return 1;
    }

    //Output result
    printf("Result: %.2lf\n", result);

    return 0;
}

//Function definitions
double addition(double left, double right) {
    return left + right;
}

double subtraction(double left, double right) {
    return left - right;
}

double multiplication(double left, double right) {
    return left * right;
}

double division(double left, double right) {
    if (right == 0) {
        printf("Error: Division by zero\n");
        exit(1);
    }
    return left / right;
}

double power(double base, double exponent) {
    return pow(base, exponent);
}

double floor_division(double left, double right) {
    if (right == 0) {
        printf("Error: Division by zero\n");
        exit(1);
    }
    return floor(left / right);
}
