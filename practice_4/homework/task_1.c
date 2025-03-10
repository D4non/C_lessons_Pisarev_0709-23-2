#include <stdio.h>
#include <strings.h>
#include <string.h>

void upper(char *string){
    for (int i = 0; string[i] != '\0'; i++) {
        string[i] = toupper((unsigned char)string[i]);
    }
}

void lower(char *string){
    for (int i = 0; string[i] != '\0'; i++) {
        string[i] = tolower((unsigned char)string[i]);
    }
}

void reverse(char *string){
    size_t len = strlen(string);
    for (int i = 0; i < len / 2; i++) {
        char temp = string[i];
        string[i] = string[len - i - 1];
        string[len - i - 1] = temp;
    }
}

typedef struct {
    char *name;
    void (*func)(char *);
} Command;

int main() {
    char string[200];
    char command[100];

    Command commands[] = {
        {"upper", upper},
        {"lower", lower},
        {"reverse", reverse},
        {"exit", NULL}
    };

    while (1) {
        printf("Введите строку: ");
        scanf(" %99[^\n]", string);

        printf("Введите команду (upper, lower, reverse, exit): ");
        scanf("%s", command);

        int flag = 0;

        for (int i = 0; commands[i].name; i++){
            if (strcasecmp(command, commands[i].name) == 0) {
                if (commands[i].func == NULL){
                    printf("Завершение работы...\n");
                    return 0;
                }
            
            commands[i].func(string);
            printf("Результат выполнения функции: %s\n\n", string);
            flag = 1;
            break;
            }
        }

        if (!flag) {
            printf("Похоже такой команды не существует :(\nПопробуйте ввести команду ещё раз\n\n");
        }
    }

    return 0;
}