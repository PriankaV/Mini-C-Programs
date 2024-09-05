#include <stdio.h>
#include <string.h>

//Defining Max numbers
#define MAX_STUDENTS 50
#define NUM_SUBJECTS 5

//A structure to store student info
struct Student {
    char name[50];
    int rollNo;
    float marks[NUM_SUBJECTS];
    float totalMarks;
    float averageMarks;
};

//Prototypes
void inputStudentData(struct Student students[], int numStudents);
void calculateGrades(struct Student students[], int numStudents);
void displayStudentData(struct Student students[], int numStudents); 
void displayClassStatistics(struct Student students[], int numStudents);
void findHighestAndLowestAverage(struct Student students[], int numStudents);

int main() {
    int numStudents;

    //Prompts the user to enter the total number of students in the class
    printf("Enter the total number of students in the class (max 50): ");
    scanf("%d", &numStudents);

    //Checks to see if the number of students exceeds the maximum limit
    if (numStudents > MAX_STUDENTS) {
        printf("Maximum number of students exceeded.\n");
        return 1;
    }

    struct Student students[MAX_STUDENTS]; // Array to store student data

    //Function calls
    inputStudentData(students, numStudents);
    calculateGrades(students, numStudents);
    displayStudentData(students, numStudents);
    displayClassStatistics(students, numStudents);
    findHighestAndLowestAverage(students, numStudents);

    return 0;
}

//Functio to get student data
void inputStudentData(struct Student students[], int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Roll No: ");
        scanf("%d", &students[i].rollNo);
        printf("Enter marks for 5 subjects:\n");
        for (int j = 0; j < NUM_SUBJECTS; j++) {
            printf("Subject %d: ", j + 1);
            scanf("%f", &students[i].marks[j]);
            // Validate marks
            if (students[i].marks[j] < 0 || students[i].marks[j] > 100) {
                printf("Marks should be between 0 and 100. Please re-enter.\n");
                j--; // Re-enter the same subject
            }
        }
    }
}

//Calculates total and average grades
void calculateGrades(struct Student students[], int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        students[i].totalMarks = 0;
        for (int j = 0; j < NUM_SUBJECTS; j++) {
            students[i].totalMarks += students[i].marks[j];
        }
        students[i].averageMarks = students[i].totalMarks / NUM_SUBJECTS;
    }
}

//Displays student data
void displayStudentData(struct Student students[], int numStudents) {
    printf("\nClass Roster:\n");
    printf("-----------------------------------------------------------------\n");
    printf("| %-20s | %-8s |", "Name", "Roll No");
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        printf(" Subject %d |", i + 1);
    }
    printf(" Total | Average |\n");
    printf("-----------------------------------------------------------------\n");

    for (int i = 0; i < numStudents; i++) {
        printf("| %-20s | %-8d |", students[i].name, students[i].rollNo);
        for (int j = 0; j < NUM_SUBJECTS; j++) {
            printf(" %-8.2f |", students[i].marks[j]);
        }
        printf(" %-5.2f | %-7.2f |\n", students[i].totalMarks, students[i].averageMarks);
    }
    printf("-----------------------------------------------------------------\n");
}

//Displays class statistics
void displayClassStatistics(struct Student students[], int numStudents) {
    float classAverage = 0;
    for (int i = 0; i < numStudents; i++) {
        classAverage += students[i].averageMarks;
    }
    classAverage /= numStudents;

    printf("\nClass Statistics:\n");
    printf("Class Average: %.2f\n", classAverage);
}

//Finds student with highest and lowest average grade
void findHighestAndLowestAverage(struct Student students[], int numStudents) {
    float highestAverage = students[0].averageMarks;
    float lowestAverage = students[0].averageMarks;
    char highestName[50];
    char lowestName[50];

    for (int i = 1; i < numStudents; i++) {
        if (students[i].averageMarks > highestAverage) {
            highestAverage = students[i].averageMarks;
            strcpy(highestName, students[i].name);
        }
        if (students[i].averageMarks < lowestAverage) {
            lowestAverage = students[i].averageMarks;
            strcpy(lowestName, students[i].name);
        }
    }

    printf("Student with the highest average grade: %s (Average: %.2f)\n", highestName, highestAverage);
    printf("Student with the lowest average grade: %s (Average: %.2f)\n", lowestName, lowestAverage);
}
