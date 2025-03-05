#include <stdio.h>
#include <string.h>

int main() {
    char message[100];
    printf("Введите зашифрованное сообщение: ");
    fgets(message, sizeof(message), stdin);

    size_t start = strspn(message, "#*");

    size_t end = strlen(message) - strcspn(message + start, "#*");

    size_t len = end - start;

    char eto_nam_nado[100];
    strncpy(eto_nam_nado, message + start, len);
    eto_nam_nado[len] = '\0';

    printf("Очищенное сообщение: %s\n", eto_nam_nado);
    printf("Длина сообщения: %zu\n", len);

    return 0;
}