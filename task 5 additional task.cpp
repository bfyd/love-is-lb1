#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

struct student {
    char famil[20];
    char name[20];
    char facult[20];
    int Nomzach;
};

void main() {
    int num, nomz, count;

    setlocale(LC_ALL, "Rus");

    printf("Введите количество студентов:\n");
    scanf("%d", &count);

    // Динамически выделяем память под массив структур student
    struct student* stud = (struct student*)malloc(count * sizeof(struct student));
    if (stud == NULL) {
        printf("Ошибка выделения памяти!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("Введите фамилию студента:\n");
        scanf("%19s", stud[i].famil); // Ограничиваем ввод для предотвращения переполнения буфера
        getchar();
    }
    for (int i = 0; i < count; i++) {
        printf("Введите имя студента %s:\n", stud[i].famil);
        scanf("%19s", stud[i].name);
    }
    for (int i = 0; i < count; i++) {
        printf("Введите название факультета студента %s %s:\n", stud[i].famil, stud[i].name);
        scanf("%19s", stud[i].facult);
    }
    for (int i = 0; i < count; i++) {
        printf("Введите номер зачётной книжки студента %s %s:\n", stud[i].famil, stud[i].name);
        scanf("%d", &stud[i].Nomzach);
    }

    for (int i = 0; i < count; i++) {
        printf("Cтудент %s %s обучается на факультете %s, номер зачётной книжки %d \n",
            stud[i].famil, stud[i].name, stud[i].facult, stud[i].Nomzach);
    }

    while (1) {
        printf("По какому полю хотите осуществить поиск:\n1- фамилия\n2- имя\n3- название факультета\n4- номер зачётной книжки\n");
        scanf("%d", &num);
        printf("Введите данные для поиска:\n");
        char search[20];
        if (num != 4) {
            scanf("%19s", search);
        }
        else {
            scanf("%d", &nomz);
        }

        int found = 0; // Для отслеживания, найден ли студент
        for (int i = 0; i < count; i++) {
            if ((num == 1 && strcmp(search, stud[i].famil) == 0) ||
                (num == 2 && strcmp(search, stud[i].name) == 0) ||
                (num == 3 && strcmp(search, stud[i].facult) == 0) ||
                (num == 4 && stud[i].Nomzach == nomz)) {
                printf("Cтудент %s %s обучается на факультете %s, номер зачётной книжки %d \n",
                    stud[i].famil, stud[i].name, stud[i].facult, stud[i].Nomzach);
                found = 1; // Студент найден
            }
        }
        if (!found) {
            printf("Студент не найден.\n");
        }
    }

    // Освобождаем память при завершении работы
    free(stud);

    getchar();
    getchar();
}
