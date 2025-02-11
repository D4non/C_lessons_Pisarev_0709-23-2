#include <stdio.h>

int main() {
    int distance;

    printf("Напишите расстояние, которое должен проехать луноход: ");
    scanf("%d", &distance);

    if (distance > 0 && distance <= 5000) {
        printf("Луноход сможет добраться до станции! \n");
    }

    else {
        printf("Луноход не доберётся :( \n");
    }
}