#include <stdio.h>
#include <ctype.h>

int main() {
    char word;

    printf("Введите символ, который хотите использовать для маркировки: ");
    scanf("%c", &word);

    if (isalpha(word)) {
        printf("Этот символ можно использовать для маркировки! \n");
    }

    else {
        printf("Этот символ недопустим :( \n");
    }
}