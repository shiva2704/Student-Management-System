include <stdio.h>
include <stdlib.h>
include <string.h>

define MAX_STUDENTS 100

struct Student {
    int id;
    char name[50];
    float marks;
};

struct Student students[MAX_STUDENTS];
int count = 0;

void addStudent() {
    if (count >= MAX_STUDENTS) {
        printf("\nStudent list is full!\n");
        return;
    }
    printf("\nEnter Student ID: ");
    scanf("%d", &students[count].id);
    printf("Enter Name: ");
    scanf(" %49[^"]", students[count].name);
    printf("Enter Marks: ");
    scanf("%f", &students[count].marks);
    count++;
    printf("Student added successfully!\n");
}

void displayStudents() {
    if (count == 0) {
        printf("\nNo students to display!\n");
        return;
    }
    printf("\nStudent List:\n");
    printf("ID\tName\tMarks\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%.2f\n", students[i].id, students[i].name, students[i].marks);
    }
}

void searchStudent() {
    int id;
    printf("\nEnter Student ID to search: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            printf("\nStudent Found:\nID: %d\nName: %s\nMarks: %.2f\n", students[i].id, students[i].name, students[i].marks);
            return;
        }
    }
    printf("\nStudent not found!\n");
}

void deleteStudent() {
    int id, i, found = 0;
    printf("\nEnter Student ID to delete: ");
    scanf("%d", &id);
    for (i = 0; i < count; i++) {
        if (students[i].id == id) {
            found = 1;
            break;
        }
    }
    if (found) {
        for (int j = i; j < count - 1; j++) {
            students[j] = students[j + 1];
        }
        count--;
        printf("Student deleted successfully!\n");
    } else {
        printf("\nStudent not found!\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nStudent Management System\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}
