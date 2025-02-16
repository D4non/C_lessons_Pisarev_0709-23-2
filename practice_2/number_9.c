#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum Condition {Sunny, Cloudy, Rainy};

typedef struct {
    float temperature;
    float humidity;
    enum Condition condition_type;
} Weather;

int main() {
    int number;
    scanf("%d", &number);
    Weather* weathers = malloc(sizeof(Weather) * number);

    for (int i = 0; i < number; i++) {
        char condition_type[50];
        scanf("%f", &weathers[i].temperature);
        scanf("%f", &weathers[i].humidity);
        scanf("%s", condition_type);

        if (strcmp(condition_type, "Sunny") == 0) {
            weathers[i].condition_type = Sunny;
        } else if (strcmp(condition_type, "Cloudy") == 0) {
            weathers[i].condition_type = Cloudy;
        } else if (strcmp(condition_type, "Rainy") == 0) {
            weathers[i].condition_type = Rainy;
        } else {
            printf("%s - такого типа погоды не существует, по умолчанию установлен тип Sunny!\n", condition_type);
            weathers[i].condition_type = Sunny;
        }
    }

    for (int i = 0; i < number; i++) {
        printf("\nTemperature: %f°C \n", weathers[i].temperature);
        printf("Humidity: %f%% \n", weathers[i].humidity);
        printf("Condition: ");
        switch (weathers[i].condition_type) {
            case 0:
                printf("Sunny\n");
                break;
            case 1:
                printf("Cloudy\n");
                break;
            case 2:
                printf("Rainy\n");
                break;
        }
        printf("\n");
    }

    return 0;
}