#include <stdio.h>

void check_fuel(int fuel_level) {
    if (fuel_level < 10) {
        printf("Предупреждение: Уровень топлива ниже 10%%!\n");
    }
}