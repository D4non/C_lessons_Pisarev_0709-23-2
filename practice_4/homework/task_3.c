#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <ctype.h>

float add(float a, float b){
    return a + b;
}

float subtract(float a, float b){
    return a - b;
}

float multiply(float a, float b){
    return a * b;
}

float divide(float a, float b) {
    if (b == 0) {
        printf("Делить на 0 нельзя!\n");
        exit(1);
    }
    return a / b;
}

typedef float (*Function)(float, float);

int main() {
    char string[200];
    float num1, num2, result;
    char znak;

    Function functions[] = {
        add,
        subtract,
        multiply,
        divide
    };

    printf("Введите выражение (например, '12 + 34'): ");
    scanf(" %99[^\n]", string);

    if (sscanf(string, "%f %c %f", &num1, &znak, &num2) != 3) {
        printf("Некорректный ввод!\n");
        return 1;
    }

    if (znak == '+') {
        result = functions[0](num1, num2);
    } else if (znak == '-') {
        result = functions[1](num1, num2);
    } else if (znak == '*') {
        result = functions[2](num1, num2);
    } else if (znak == '/') {
        result = functions[3](num1, num2);
    } else {
        printf("Такой операции нет!\n");
        return 1;
    }

    printf("Результат: %.2f\n", result);

    return 0;
}