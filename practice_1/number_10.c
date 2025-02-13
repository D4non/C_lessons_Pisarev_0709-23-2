#include <stdio.h>

int main() {
    int temepreture;

    printf("Введите температуру корпуса спутника: ");
    scanf("%d", &temepreture);

    if (temepreture >= -150 && temepreture <= 120) {
        printf("Это допустимая температура!!! \n");
    } else {
        printf("Это не допустимая температура :_( \n");
    }
}