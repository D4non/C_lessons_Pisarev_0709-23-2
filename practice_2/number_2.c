#include <stdio.h>
#include <stdlib.h>

struct Item {
    char item[50];
    int quantity;
    float price;
};

int main() {
    int number;
    scanf("%d", &number);
    struct Item* items = malloc(sizeof(struct Item) * number);
    
    for (int i = 0; i < number; i++) {
        scanf("%s", items[i].item);
        scanf("%d", &items[i].quantity);
        scanf("%f", &items[i].price);
    }
    
    for (int i = 0; i < number; i++) {
        printf("\nItem: %s \n", items[i].item);
        printf("Quantity: %d \n", items[i].quantity);
        printf("Price: %f \n", items[i].price);
        printf("\n");
    }
}