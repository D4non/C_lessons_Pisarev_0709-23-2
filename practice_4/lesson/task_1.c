#include <stdio.h>

int main() {
    char ships[100][50];
    int num;

    printf("Введите количество кораблей: ");
    scanf("%d", &num);

    for (int i = 0; i < num; i++) {
        printf("Введите название корабля: ");
        scanf("%s", ships[i]);
    }

    int flag;

    for (int i = 0; i < num; i++) {
        if (strncmp(ships[i], "SS", 2) == 0) {
            printf("Найден корабль: %s\n", ships[i]);
            flag = 1;
            break;
        }
    }

    if (!flag) {
        printf("Корабль не найден :(\n");
    }

    return 0;
}