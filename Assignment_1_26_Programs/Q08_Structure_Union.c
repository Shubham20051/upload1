#include <stdio.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    float marks;
};

union Data {
    int integerValue;
    float floatValue;
    char text[50];
};

int main(void)
{
    struct Student student;
    union Data data;
    int choice;

    printf("STRUCTURE AND UNION DEMONSTRATION\n");
    printf("Enter student roll number: ");
    if (scanf("%d", &student.roll) != 1 || student.roll <= 0) {
        printf("Invalid roll number.\n");
        return 1;
    }
    printf("Enter student marks (0-100): ");
    if (scanf("%f", &student.marks) != 1 || student.marks < 0 || student.marks > 100) {
        printf("Invalid marks.\n");
        return 1;
    }
    getchar();
    printf("Enter student name: ");
    if (!fgets(student.name, sizeof student.name, stdin)) {
        printf("Input error.\n");
        return 1;
    }
    student.name[strcspn(student.name, "\n")] = '\0';

    printf("\nStructure stores all fields together:\n");
    printf("Roll number: %d\nName: %s\nMarks: %.2f\n",
           student.roll, student.name, student.marks);

    printf("\nChoose union data type:\n1. Integer\n2. Float\n3. Text\nEnter choice: ");
    if (scanf("%d", &choice) != 1 || choice < 1 || choice > 3) {
        printf("Invalid choice.\n");
        return 1;
    }
    if (choice == 1) {
        printf("Enter an integer: ");
        if (scanf("%d", &data.integerValue) != 1) {
            printf("Invalid integer.\n");
            return 1;
        }
        printf("Union integer value: %d\n", data.integerValue);
    } else if (choice == 2) {
        printf("Enter a float: ");
        if (scanf("%f", &data.floatValue) != 1) {
            printf("Invalid float.\n");
            return 1;
        }
        printf("Union float value: %.2f\n", data.floatValue);
    } else {
        getchar();
        printf("Enter text: ");
        if (!fgets(data.text, sizeof data.text, stdin)) {
            printf("Input error.\n");
            return 1;
        }
        data.text[strcspn(data.text, "\n")] = '\0';
        printf("Union text value: %s\n", data.text);
    }
    printf("A union shares memory among its members; only the last assigned member is meaningful.\n");
    return 0;
}
