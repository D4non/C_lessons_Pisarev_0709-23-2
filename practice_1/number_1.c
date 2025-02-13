#include <stdio.h>

int main() {
    int weight;
    
    printf("Введите вашу массу: ");
    scanf("%d", &weight);

    if (weight > 60 || weight < 90) {
        printf("Вы прошли отбор!\n");
    }

    else {
        printf("Вы не прошли отбор!\n");
    }
    return 0;
}
