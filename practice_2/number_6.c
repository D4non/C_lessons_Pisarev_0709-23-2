#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum EngineType {Gasoline, Diesel, Electric};

typedef struct {
    char brand[50];
    char model[50];
    int year;
    enum EngineType engine_type;
} Vehicle;

int main() {
    int number;
    scanf("%d", &number);
    Vehicle* vehicles = malloc(sizeof(Vehicle) * number);

    for (int i = 0; i < number; i++) {
        char engine_type[50];
        scanf("%s", vehicles[i].brand);
        scanf("%s", vehicles[i].model);
        scanf("%d", &vehicles[i].year);
        scanf("%s", engine_type);

        if (strcmp(engine_type, "Gasoline") == 0) {
            vehicles[i].engine_type = Gasoline;
        } else if (strcmp(engine_type, "Diesel") == 0) {
            vehicles[i].engine_type = Diesel;
        } else if (strcmp(engine_type, "Electric") == 0) {
            vehicles[i].engine_type = Electric;
        } else {
            printf("%s - такого типа двигателя не существует, по умолчанию установлен тип Gasoline!\n", engine_type);
            vehicles[i].engine_type = Gasoline;
        }
    }

    for (int i = 0; i < number; i++) {
        printf("\nVehicle: %s %s \n", vehicles[i].brand, vehicles[i].model);
        printf("Year: %d \n", vehicles[i].year);
        printf("Engine Type: ");
        switch (vehicles[i].engine_type) {
            case 0:
                printf("Gasoline\n");
                break;
            case 1:
                printf("Diesel\n");
                break;
            case 2:
                printf("Electric\n");
                break;
        }
        printf("\n");
    }

    return 0;
}