#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int credits;
    char professor[50];
} Course;

int main() {
    int number;
    printf("Введите количество курсов: ");
    scanf("%d", &number);
    Course* courses = malloc(sizeof(Course) * number);

    for (int i = 0; i < number; i++) {
        printf("Введите и нформацию о курсе: ");
        scanf("%s", courses[i].name);
        scanf("%d", &courses[i].credits);
        scanf("%s", courses[i].professor);
    }
    
    for (int i = 0; i < number; i++) {
        printf("\nCourse: %s \n", courses[i].name);
        printf("Credits: %d \n", courses[i].credits);
        printf("Professor: %s \n", courses[i].professor);
        printf("\n");
    }

    return 0;
}