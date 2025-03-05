#include <stdio.h>
#include <string.h>

int main() {
    char string[100];
    printf("Введите строку: ");
    fgets(string, sizeof(string), stdin);

    char *word;

    word = strtok(string, ";");
    while (word) {
        printf("%s\n", word);
        word = strtok(NULL, ";");
    }

    return 0;
}