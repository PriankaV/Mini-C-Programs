#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_SUBJECTS 5

//Student structure
typedef struct Student {
    char name[50];
    int roll_number;
    int marks[NUM_SUBJECTS];
    float total_marks;
    float average_marks;
    struct Student *next;
} Student;

//Function to create a new student node
Student* createStudent() {
    Student *new_student = (Student*)malloc(sizeof(Student));
    if (new_student == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    new_student->next = NULL;
    return new_student;
}

//Function to calculate total and average marks for a student
void calculateMarks(Student *student) {
    student->total_marks = 0;
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        student->total_marks += student->marks[i];
    }
    student->average_marks = student->total_marks / NUM_SUBJECTS;
}

//Function to insert a student node into the linked list
void insertStudent(Student **head) {
    Student *new_student = createStudent();

    printf("Enter student name: ");
    scanf("%s", new_student->name);
    printf("Enter roll number: ");
    scanf("%d", &new_student->roll_number);
    printf("Enter marks for %d subjects:\n", NUM_SUBJECTS);
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        printf("Subject %d: ", i + 1);
        scanf("%d", &new_student->marks[i]);
    }

    calculateMarks(new_student);

    //Insert at the beginning of the list
    new_student->next = *head;
    *head = new_student;
}

//Function to display student information
void displayStudents(Student *head) {
    printf("\n%-20s %-12s %-12s %-12s %-12s %-12s\n", "Name", "Roll Number", "Subject 1", "Subject 2", "Subject 3", "Subject 4", "Subject 5", "Total", "Average");
    printf("---------------------------------------------------------------\n");
    while (head != NULL) {
        printf("%-20s %-12d %-12d %-12d %-12d %-12d %-12d %-12.2f %-12.2f\n", head->name, head->roll_number,
               head->marks[0], head->marks[1], head->marks[2], head->marks[3], head->marks[4],
               head->total_marks, head->average_marks);
        head = head->next;
    }
    printf("---------------------------------------------------------------\n");
}

//Function to calculate class average
float calculateClassAverage(Student *head) {
    float total_average = 0.0;
    int count = 0;
    while (head != NULL) {
        total_average += head->average_marks;
        count++;
        head = head->next;
    }
    return total_average / count;
}

//Function to find student with highest and lowest average grades
void findExtremeGrades(Student *head, Student **highest, Student **lowest) {
    *highest = head;
    *lowest = head;
    while (head != NULL) {
        if (head->average_marks > (*highest)->average_marks)
            *highest = head;
        if (head->average_marks < (*lowest)->average_marks)
            *lowest = head;
        head = head->next;
    }
}

int main() {
    Student *head = NULL;
    char choice;
    do {
        insertStudent(&head);
        printf("Do you want to add another student? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    displayStudents(head);

    float class_average = calculateClassAverage(head);
    printf("Class Average: %.2f\n", class_average);

    Student *highest_grade, *lowest_grade;
    findExtremeGrades(head, &highest_grade, &lowest_grade);
    printf("Student with Highest Average Grade: %s (Average Grade: %.2f)\n", highest_grade->name, highest_grade->average_marks);
    printf("Student with Lowest Average Grade: %s (Average Grade: %.2f)\n", lowest_grade->name, lowest_grade->average_marks);

    return 0;
}
