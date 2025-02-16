#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[50];
    int age;
    float gpa;
};

int main() {
    int number;
    scanf("%d", &number);
    struct Student* students = malloc(sizeof(struct Student) * number);
    
    for (int i = 0; i < number; i++) {
        scanf("%s", students[i].name);
        scanf("%d", &students[i].age);
        scanf("%f", &students[i].gpa);
    }
    
    for (int i = 0; i < number; i++) {
        printf("\nName: %s \n", students[i].name);
        printf("Age: %d \n", students[i].age);
        printf("GPA: %f \n", students[i].gpa);
        printf("\n");
    }
}