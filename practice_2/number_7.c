#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int age;
    float gpa;
} Student;

void print_student(Student* student) {
    printf("\nName: %s \n", student->name); // предсказывая вопрос, что такое "->", это тоже самое что (*student).name
    printf("Age: %d \n", student->age);
    printf("GPA: %f \n", student->gpa);
    printf("\n");
}

int main() {
    int number;
    scanf("%d", &number);
    Student* students = malloc(sizeof(Student) * number);
    
    for (int i = 0; i < number; i++) {
        printf("Введите информацию о студенте: ");
        scanf("%s", students[i].name);
        scanf("%d", &students[i].age);
        scanf("%f", &students[i].gpa);
    }
    
    for (int i = 0; i < number; i++) {
        print_student(&students[i]);
    }

    free(students);

    return 0;
}