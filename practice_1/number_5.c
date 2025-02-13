#include <stdio.h>

int main() {
    float raschet, fact;

    printf("Введите расчётную скорость: ");
    scanf("%f", &raschet);
    printf("Введите фактическую скорость: ");
    scanf("%f", &fact);

    if (fact >= raschet + 0.1 || fact <= raschet - 0.1) {
        printf("Орбита спутника нестабильна! \n");
    } else {
        printf("Орбита спутника стабильна! \n");
    }
}