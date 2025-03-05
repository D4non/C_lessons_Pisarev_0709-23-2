#include <stdio.h>
#include <string.h>

int main() {
    char file[200];
    printf("Введите секретный отчёт: ");
    fgets(file, sizeof(file), stdin);

    size_t len = strlen(file);
    if (len > 0 && file[len - 1] == '\n') {
        file[len - 1] = '\0';
    }

    char *copy = strdup(file);

    printf("Оригинал: %s\n", file);
    printf("Копия: %s\n", copy);

    return 0;
}