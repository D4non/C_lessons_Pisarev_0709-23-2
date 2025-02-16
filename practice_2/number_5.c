#include <stdio.h>

union Data {
    int i;
    float f;
    char c[50];
};

int main() {
    union Data data;
    int number;

    printf("Введите число (1 - int; 2 - float; 3 - char): ");
    scanf("%d", &number);
    printf("Введите информацию, которую хотите сохранить: ");

    if (number == 1) {
        scanf("%d", &data.i);
        printf("Integer: %d\n", data.i);
    } else if (number == 2) {
        scanf("%f", &data.f);
        printf("Float: %f\n", data.f);
    } else if (number == 3) {
        scanf("%s", data.c);
        printf("String: %s\n", data.c);
    } else {
        printf("Недопустимое значение!\n");
    }
    
    return 0;
}