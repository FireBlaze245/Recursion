// Tasks_adn_solutions
// Задача 1
// Напишите рекурсивную функцию для вычисления факториала числа n!
// Решение: 

int factorial(int n) {
    if (n == 0) return 1;           // Базовый случай
    return n * factorial(n - 1);    // Рекурсивный шаг
}
    
// Задача 2
// Рекурсивно вычислите сумму всех чисел от 1 до n
// Решение: 

int sum_up_to(int n) {
    if (n == 1) return 1;
    return n + sum_up_to(n - 1);
}

// Задача 3
// Возведите x в степень n (n >= 0) рекурсивно
// Решение: 

int power(int x, int n) {
    if (n == 0) return 1;
    return x * power(x, n - 1);
}

// Задача 4
// Повышенная сложность
// Рекурсивно разверните строку (выведите символы в обратном порядке)
// Решение:

#include <string.h>
void reverse_string(char str[], int index) {
    int len = strlen(str);
    if (index == len) return;        //Базовый случай
    reverse_string(str, index + 1);  //Спуск до конца строки
    printf("%c", str[index]);        //Подъем и вывод символов
}
    
// Или альтернативное решение с двумя указателями:
 
void reverse(char str[], int left, int right) {
    if (left >= right) return;
     Меняем местами
    char temp = str[left];
    str[left] = str[right];
    str[right] = temp;
    reverse(str, left + 1, right - 1);
}

// Задача 5
// Проверьте, является ли строка палиндромом (читается одинаково слева направо и справа налево)
// Решение: 

int is_palindrome(char str[], int left, int right) {
    // Базовый случай: пустая строка или один символ
    if (left >= right) return 1;
    // Если символы не совпадают, не палиндром
    if (str[left] != str[right]) return 0;
    // Проверяем внутреннюю часть
    return is_palindrome(str, left + 1, right - 1);
}
