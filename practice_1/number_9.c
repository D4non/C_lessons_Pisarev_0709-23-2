#include <stdio.h>

int main() {
    double t;

    printf("Введите время передачи сообщения в секундах: ");
    scanf("%lf", &t);

    if (t >= 0) {
        int minute = t / 60;
        printf("Ваше сообщение будет передаваться %d минут %.0lf секунд \n", minute, (t - (60 * minute)));
    } else {
        printf("Ваше сообщение не может быть передано \n");
    }
}
