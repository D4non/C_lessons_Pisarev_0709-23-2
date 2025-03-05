#include <stdio.h>
#include <strings.h>

int main() {
    char code[] = "LAUNCH-2025";

    char input_code[100];
    printf("Введите код для запуска ракеты: ");
    scanf("%s", input_code);

    if (strcasecmp(input_code, code) == 0) {
        printf("Код принят!\n");
        system("poweroff");
    } else {
        printf("Ошибка: неверный код!\n");
    }

    return 0;
}