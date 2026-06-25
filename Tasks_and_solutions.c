#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
 
// прототипы функций...
int factorial(int n);
int sum_up_to(int n);
int power(int x, int n);
void reverse_string_print(char str[], int index);
void reverse_string_inplace(char str[], int left, int right);
int is_palindrome(char str[], int left, int right);
void show_task1(int mode);
void show_task2(int mode);
void show_task3(int mode);
void show_task4(int mode);
void show_task5(int mode);

// задача 1. факториал.
int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

void show_task1(int mode) {
    if (mode == 1) {
        printf("\nрешение задачи 1\n");
        printf("int factorial(int n) {\n");
        printf("    if (n == 0) return 1;\n");
        printf("    return n * factorial(n - 1);\n");
        printf("}\n");
    }
    else {
        int n;
        printf("\nзапуск задачи 1\n");
        printf("Введите число для вычисления факториала: ");
        scanf_s("%d", &n);
        if (n < 0) {
            printf("Ошибка: факториал определён только для неотрицательных чисел!\n");
        }
        else {
            printf("%d! = %d\n", n, factorial(n));
        }
    }
}

// задача 2 сумма от 1 до n
int sum_up_to(int n) {
    if (n == 1) return 1;
    return n + sum_up_to(n - 1);
}

void show_task2(int mode) {
    if (mode == 1) {
        printf("\nрешение задачи 2\n");
        printf("int sum_up_to(int n) {\n");
        printf("    if (n == 1) return 1;\n");
        printf("    return n + sum_up_to(n - 1);\n");
        printf("}\n");
    }
    else {
        int n;
        printf("\nзапуск задачи 2\n");
        printf("Введите n (сумма от 1 до n): ");
        scanf_s("%d", &n);
        if (n < 1) {
            printf("Ошибка: n должно быть >= 1!\n");
        }
        else {
            printf("Сумма от 1 до %d = %d\n", n, sum_up_to(n));
        }
    }
}

// задача 3 вовзведение в степень
int power(int x, int n) {
    if (n == 0) return 1;
    return x * power(x, n - 1);
}

void show_task3(int mode) {
    if (mode == 1) {
        printf("\nрешение задачи 3\n");
        printf("int power(int x, int n) {\n");
        printf("    if (n == 0) return 1;\n");
        printf("    return x * power(x, n - 1);\n");
        printf("}\n");
    }
    else {
        int x, n;
        printf("\nзапуск задачи 3\n");
        printf("Введите основание x: ");
        scanf_s("%d", &x);
        printf("Введите степень n (>= 0): ");
        scanf_s("%d", &n);
        if (n < 0) {
            printf("Ошибка: степень должна быть >= 0!\n");
        }
        else {
            printf("%d^%d = %d\n", x, n, power(x, n));
        }
    }
}

// задача 4 разворот строки
void reverse_string_print(char str[], int index) {
    int len = strlen(str);
    if (index == len) return;
    reverse_string_print(str, index + 1);
    printf("%c", str[index]);
}

void reverse_string_inplace(char str[], int left, int right) {
    if (left >= right) return;
    char temp = str[left];
    str[left] = str[right];
    str[right] = temp;
    reverse_string_inplace(str, left + 1, right - 1);
}

void show_task4(int mode) {
    if (mode == 1) {
        printf("\nрешение задачи 4\n");
        printf("// Вариант 1: рекурсивный вывод в обратном порядке\n");
        printf("void reverse_string_print(char str[], int index) {\n");
        printf("    int len = strlen(str);\n");
        printf("    if (index == len) return;\n");
        printf("    reverse_string_print(str, index + 1);\n");
        printf("    printf(\"%%c\", str[index]);\n");
        printf("}\n\n");
        printf("// Вариант 2: разворот с изменением строки\n");
        printf("void reverse_string_inplace(char str[], int left, int right) {\n");
        printf("    if (left >= right) return;\n");
        printf("    char temp = str[left];\n");
        printf("    str[left] = str[right];\n");
        printf("    str[right] = temp;\n");
        printf("    reverse_string_inplace(str, left + 1, right - 1);\n");
        printf("}\n");
    }
    else {
        char str[100];
        printf("\nзапуск задачи 4\n");
        printf("Введите строку: ");
        scanf_s("%s", str, (unsigned)sizeof(str));

        printf("Вариант 1 (вывод в обратном порядке): ");
        reverse_string_print(str, 0);
        printf("\n");

        char str_copy[100];
        strcpy(str_copy, str);
        reverse_string_inplace(str_copy, 0, (int)strlen(str_copy) - 1);
        printf("Вариант 2 (разворот строки): %s\n", str_copy);
    }
}

// задача 5 проверка полиндрома
int is_palindrome(char str[], int left, int right) {
    if (left >= right) return 1;
    if (str[left] != str[right]) return 0;
    return is_palindrome(str, left + 1, right - 1);
}

void show_task5(int mode) {
    if (mode == 1) {
        printf("\nрешение задачи 5\n");
        printf("int is_palindrome(char str[], int left, int right) {\n");
        printf("    if (left >= right) return 1;\n");
        printf("    if (str[left] != str[right]) return 0;\n");
        printf("    return is_palindrome(str, left + 1, right - 1);\n");
        printf("}\n");
    }
    else {
        char str[100];
        printf("\nзапуск задачи 5\n");
        printf("Введите строку: ");
        scanf_s("%s", str, (unsigned)sizeof(str));

        int result = is_palindrome(str, 0, (int)strlen(str) - 1);
        if (result) {
            printf("\"%s\" - является палиндромом!\n", str);
        }
        else {
            printf("\"%s\" - НЕ является палиндромом!\n", str);
        }
    }
}

// ========== ГЛАВНАЯ ФУНКЦИЯ ==========
int main() {
    // НАСТРОЙКА ДЛЯ КИРИЛЛИЦЫ
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int choice, mode;

    while (1) {
        printf("1. Факториал числа n!\n");
        printf("2. Сумма чисел от 1 до n\n");
        printf("3. Возведение x в степень n\n");
        printf("4. Разворот строки\n");
        printf("5. Проверка палиндрома\n");
        printf("0. Выход\n");
        printf("Выберите задачу: ");
        scanf_s("%d", &choice);

        if (choice == 0) {
            printf("До свидания!\n");
            break;
        }

        if (choice < 1 || choice > 5) {
            printf("Неверный выбор! Попробуйте снова.\n");
            continue;
        }

        printf("1. Показать РЕШЕНИЕ (код)\n");
        printf("2. Запустить ВЫПОЛНЕНИЕ\n");
        printf("Выберите режим: ");
        scanf_s("%d", &mode);

        if (mode != 1 && mode != 2) {
            printf("Неверный режим!\n");
            continue;
        }

        // Вызов соответствующей функции
        switch (choice) {
        case 1: show_task1(mode); break;
        case 2: show_task2(mode); break;
        case 3: show_task3(mode); break;
        case 4: show_task4(mode); break;
        case 5: show_task5(mode); break;
        }

        printf("\nНажмите Enter для продолжения...");
        getchar();
        getchar();
    }

    return 0;
}
