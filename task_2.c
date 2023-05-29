#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10//розмір масиву
#define MIN_VALUE -100
#define MAX_VALUE 100//межі для випадкового числа

int findMaxElementIndex(int array[], int size);//повертає номер максимального елемента масиву за модулем:
int calculateProductAfterFirstPositive(int array[], int size);//обчислює добуток елементів масиву, розташованих після першого додатного елемента
void initializeArray(int array[], int size);// ініціалізує масив випадковими числами з вказаного діапазону
void printArray(int array[], int size);//виводить елементи

int main() {
    int array[SIZE];
  
    // Ініціалізація масиву
    initializeArray(array, SIZE);

    // Виведення масиву на екран
    printf("Масив: ");
    printArray(array, SIZE);

    // Знаходження номера максимального за модулем елемента
    int maxIndex = findMaxElementIndex(array, SIZE);
    printf("Номер максимального за модулем елемента: %d\n", maxIndex);

    // Обчислення добутку елементів, розташованих після першого додатного елемента
    int product = calculateProductAfterFirstPositive(array, SIZE);
    printf("Добуток елементів після першого додатного елемента: %d\n", product);

    return 0;
}
//знаходження номера максимального за модулем елемента.
int findMaxElementIndex(int array[], int size)//приймає два аргументи: масив та його розмір
 {
    int maxIndex = 0;//ініціалізуються значеннями першого елемента масиву (у модулі)
    int maxValue = abs(array[0]);//ініціалізуються індексом першого елемента масиву. 
    for (int i = 1; i < size; i++) {
        if (abs(array[i]) > maxValue)//перевіряється чи модуль поточного ел. більший макс. ел.
        {
            maxValue = abs(array[i]);
            maxIndex = i;//якщо умова виконується-значення оновлюється
        }
    }

    return maxIndex;
}
//обчислення добутку елементів масиву, які розташовані після першого додатного елемента.
int calculateProductAfterFirstPositive(int array[], int size) {
    int product = 1;
    int firstPositiveFound = 0;

    for (int i = 0; i < size; i++) {
        if (array[i] >= 0) {
            firstPositiveFound = 1;
        }

        if (firstPositiveFound) {
            product *= array[i];
        }
    }

    return product;
}

//генератор випадкових чисел
void initializeArray(int array[], int size) {
    srand(time(NULL));//генератор

    for (int i = 0; i < size; i++) {
        array[i] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;//вираз який генерує випадкове число
    }
}
//виведення випадкових чисел
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}