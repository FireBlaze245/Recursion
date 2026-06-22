# Recursion
Рекурсия — функция вызывает саму себя.
--Спуск и подъем по стеку вызовов--
Когда функция вызывает себя, каждое новое состояние сохраняется в стеке вызовов (call stack):

Спуск (погружение)
- Каждый рекурсивный вызов создает новый "слой" на стеке
- Сохраняются локальные переменные и параметры
- Процесс продолжается до достижения базового случая (условия остановки)

Подъем (возврат)
- После достижения базового случая начинается обратный ход
- Каждый слой стека "разворачивается"
- Возвращаемые значения передаются вверх по цепочке

Ниже приведена простая реализация:

    void example(int n) {
        printf("Вход: n = %d\n", n);   Спуск
        if (n == 0) {                   Базовый случай
            printf("Достигнут базовый случай!\n");
            return;
        }
        example(n - 1);                 Рекурсивный вызов
        printf("Выход: n = %d\n", n);   Подъем
    }



Простые задачки

Задача 1
Напишите рекурсивную функцию для вычисления факториала числа n!
Решение: 

    int factorial(int n) {
        if (n == 0) return 1;            Базовый случай
        return n * factorial(n - 1);      Рекурсивный шаг
    }
    
Задача 2
Рекурсивно вычислите сумму всех чисел от 1 до n
Решение: 

    int sum_up_to(int n) {
        if (n == 1) return 1;
        return n + sum_up_to(n - 1);
    }

Задача 3
Возведите x в степень n (n >= 0) рекурсивно
Решение: 

    int power(int x, int n) {
        if (n == 0) return 1;
        return x * power(x, n - 1);
    }

Задача 4
Повышенная сложность
Рекурсивно разверните строку (выведите символы в обратном порядке)
Решение:

    #include <string.h>
    void reverse_string(char str[], int index) {
        int len = strlen(str);
        if (index == len) return;  Базовый случай
        reverse_string(str, index + 1);  Спуск до конца строки
        printf("%c", str[index]);  Подъем и вывод символов
    }
    
 Или альтернативное решение с двумя указателями:
 
    void reverse(char str[], int left, int right) {
        if (left >= right) return;
         Меняем местами
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        reverse(str, left + 1, right - 1);
    }

Задача 5
Проверьте, является ли строка палиндромом (читается одинаково слева направо и справа налево)
Решение: 

    int is_palindrome(char str[], int left, int right) {
         Базовый случай: пустая строка или один символ
        if (left >= right) return 1;
         Если символы не совпадают, не палиндром
        if (str[left] != str[right]) return 0;
         Проверяем внутреннюю часть
        return is_palindrome(str, left + 1, right - 1);
    }

Примеры рекурсии из реальной жизни.\nБыстрая сортировка: 

    void quick_sort(int arr[], int low, int high) {
        if (low >= high) return;   Базовый случай
    
        int pivot = partition(arr, low, high);   Разделение
        quick_sort(arr, low, pivot - 1);         Левая часть
        quick_sort(arr, pivot + 1, high);        Правая часть
    }

Так же подходит для бинарного поиска

    int binary_search(int arr[], int left, int right, int target) {
    
        if (left > right) return -1;
        int mid = left + (right - left) / 2;
    
        if (arr[mid] == target) return mid;
        if (arr[mid] > target)
            return binary_search(arr, left, mid - 1, target);
        return binary_search(arr, mid + 1, right, target);
    }

Рекурсия и указатели
Обход связного списка (рекурсивно)

    struct Node {
        int data;
        struct Node* next;
    };
    void print_list(struct Node* head) {
        if (head == NULL) return;   Конец списка
        printf("%d ", head->data);
        print_list(head->next);     Переход к следующему
    }
     Рекурсивное удаление списка
    void free_list(struct Node* head) {
        if (head == NULL) return;
        free_list(head->next);      Сначала удаляем хвост
        free(head);                 Потом текущий элемент
    }
