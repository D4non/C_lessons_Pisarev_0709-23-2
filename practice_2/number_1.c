#include <stdio.h>

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
        scanf("%c", &students[i].name);
        scanf("%d", &students[i].age);
        scanf("%f", &students[i].gpa);
    }
    
    for (int i = 0; i < number; i++) {
        printf("Name: %c \n", students[i].name);
        printf("Name: %d \n", students[i].age);
        printf("Name: %f \n", students[i].gpa);
        printf("\n");
    }
}