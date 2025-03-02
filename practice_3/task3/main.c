#include <stdio.h>

int main() {
    float speed, time;
    int fuel_level;

    printf("Введите скорость корабля (км/ч): ");
    scanf("%f", &speed);

    printf("Введите время полета (часы): ");
    scanf("%f", &time);

    printf("Введите уровень топлива (%%): ");
    scanf("%d", &fuel_level);

    float distance = calculate_distance(speed, time);
    printf("Расстояние: %.2f км\n", distance);

    check_fuel(fuel_level);

    return 0;
}