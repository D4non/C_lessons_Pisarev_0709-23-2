#include <stdio.h>

int main() {
    int cargo;

    printf("Введите вес вашего груза: ");
    scanf("%d", &cargo);

    if (cargo % 4 == 0 && cargo > 0) {
        printf("Ваш груз можно поместить на корабль, разделив его по %d килограмм в отсеке \n", cargo / 4);
    } else {
        printf("Ваш груз нельзя перевезти на корабле :_( \n");
    }
}