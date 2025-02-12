#include <stdio.h>

int main() {
    int today, date;
    today = 20250212;

    printf("Введите дату экспидиции (например: 20250212 (12 февраля 2025 года)): ");
    scanf("%d", &date);

    if (date == today) {
        printf("ОГО! Экспидиция уже СЕГОДНЯ! \n");
    } else if (date > today) {
        printf("Можно отдохнуть, экспидиция ещё не скоро ))) \n");
    } else {
        printf("О НЕТ! ТЫ ПРОСПАЛ! Экспедиция уже прошла :_( \n");
    }
}