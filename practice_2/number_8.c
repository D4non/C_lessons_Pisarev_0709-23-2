#include <stdio.h>

typedef union {
    int grade_int;
    char grade_str[10];
} Grade;

int main() {
    int number;
    scanf("%d", &number);
    Grade grades[number];

    for (int i = 0; i < number; i++) {
        int type;
        printf("Введите тип оценки (1 - числовая оценка, 2 - строковая оценка): ");
        scanf("%d", &type);

        if (type == 1) {
            printf("Введите оценку: ");
            scanf("%d", &grades[i].grade_int);
            if (grades[i].grade_int < 0 || grades[i].grade_int > 100) {
                printf("Ошибка! Оценка должна быть в пределах от 0 до 100! \n");
                i --;
            } else {
                printf("\nGrade: %d \n", grades[i].grade_int);
            }
        } else if (type == 2) {
            printf("Введите оценку: ");
            scanf("%s", grades[i].grade_str);
            printf("\nGrade: %s \n", grades[i].grade_str);
        } else {
            printf("Недопустимый тип! \n");
            i--;
        }
    }

    return 0;
}