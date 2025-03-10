#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <ctype.h>

void remove_spaces(char *string){
    int i, j = 0;
    for (i = 0; string[i] != '\0'; i++) {
        if (string[i] != ' ') {
            string[j++] = string[i];
        }
    }
    string[j] = '\0';
}

void replace_stars(char *string){
    char *words = "aeiouyAEIOUY";

    for (int i = 0; string[i] != '\0'; i++) {
        if (strchr(words, string[i]) != NULL) {
            string[i] = '*';
        }
    }
}

void invert_case(char *string){
    for (int i = 0; string[i] != '\0'; i++) {
        if (isupper((unsigned char)string[i])) {
            string[i] = tolower((unsigned char)string[i]);
        } else if (islower((unsigned char)string[i])) {
            string[i] = toupper((unsigned char)string[i]);
        }
    }
}

typedef void (*Function)(char*);

int main() {
    char input[200];
    char command[100];

    Function functions[] = {
        remove_spaces,
        replace_stars,
        invert_case
    };

    printf("Введите строку: ");
    // scanf(" %99[^\n]", input);  я не знаю почему не работает
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    char *string = malloc(200);
    if (!string) return 1;

    strcpy(string, input);

    printf("Доступные функции:\n 1.Удаление пробелов\n 2.Замена гласных на *\n 3.Инвертирование регистра\n");

    printf("Введите номера функций через пробел (например, 1 2 3): ");
    fgets(command, sizeof(command), stdin);

    char *token = strtok(command, " ");
    while (token != NULL) {
        int choice = atoi(token) - 1;
        if (choice >= 0 && choice < sizeof(functions) / sizeof(functions[0])) {
            functions[choice](string);
            printf("%d: %s\n", choice + 1, string);
        } else {
            printf("Неверный выбор: %s\n", token);
        }
        token = strtok(NULL, " ");
    }

    printf("Итоговый результат: %s\n", string);

    free(string);
    return 0;
}