#include <stdio.h>

int main() {
    int astronauts;

    printf("Введите количество космонавтов: ");
    scanf("%d", &astronauts);

    int flag = 0;

    for (int module_4 = 0; module_4 <= astronauts / 4; module_4++) {
        for (int module_3 = 0; module_3 <= astronauts / 3; module_3++) {
            for (int module_2 = 0; module_2 <= astronauts / 2; module_2++) {
                if (module_4 * 4 + module_3 * 3 + module_2 * 2 == astronauts) {
                    printf("Вариант комплектации: %d 4-х местных, %d 3-х местных и %d 2-х местных \n", module_4, module_3, module_2);
                    flag = 1;
                }
            }
        }
    }

    if (!flag) {
        printf("Невозможно подобрать комбинацию :_( \n");
    }
}