#include <stdio.h>
#include <stdlib.h>

struct Date {
    int day;
    int month;
    int year;
};

struct Event {
    char event[50];
    struct Date date;
    char description[100];
};

int main() {
    int number;
    scanf("%d", &number);
    struct Event* events = malloc(sizeof(struct Event) * number);
    
    for (int i = 0; i < number; i++) {
        scanf("%s", events[i].event);
        scanf("%d", &events[i].date.day);
        scanf("%d", &events[i].date.month);
        scanf("%d", &events[i].date.year);
        scanf("%s", events[i].description);
    }
    
    for (int i = 0; i < number; i++) {
        printf("\nEvent: %s \n", events[i].event);
        printf("Date: %d/%d/%d \n", events[i].date.day, events[i].date.month, events[i].date.year);
        printf("Description: %s \n", events[i].description);
        printf("\n");
    }

    return 0;
}