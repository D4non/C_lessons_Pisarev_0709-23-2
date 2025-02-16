#include <stdio.h>
#include <stdlib.h>

struct Employee {
    char name[50];
    char position[100];
    float salary;
};

int main() {
    int number;
    scanf("%d", &number);
    struct Employee* employees = malloc(sizeof(struct Employee) * number);
    
    for (int i = 0; i < number; i++) {
        scanf("%s", employees[i].name);
        scanf("%s", employees[i].position);
        scanf("%f", &employees[i].salary);
    }
    
    for (int i = 0; i < number; i++) {
        printf("\nName: %s \n", employees[i].name);
        printf("Position: %s \n", employees[i].position);
        printf("Salary: %f \n", employees[i].salary);
        printf("\n");
    }

    return 0;
}