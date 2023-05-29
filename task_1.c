#include <stdio.h>

int Quarter(float x, float y)//приймає два аргументи x і y, які представляють координати точки
 {
    if (x > 0 && y > 0) {
        return 1;
    } else if (x < 0 && y > 0) {
        return 2;
    } else if (x < 0 && y < 0) {
        return 3;
    } else if (x > 0 && y < 0) {
        return 4;
    } else {
        return 0; // Точка лежить на координатних осях або в початку координат
    }
}

int main() {
    float x1, y1, x2, y2, x3, y3;//змінні для зберігання координатних точок
    int quarter1, quarter2, quarter3;//змінні для зберігання четвертей

    // Введення координат для трьох точок
    printf("Введіть координати для точки 1 (x y): ");
    scanf("%f %f", &x1, &y1);

    printf("Введіть координати для точки 2 (x y): ");
    scanf("%f %f", &x2, &y2);

    printf("Введіть координати для точки 3 (x y): ");
    scanf("%f %f", &x3, &y3);

    // Визначення номерів координатних чвертей
    quarter1 = Quarter(x1, y1);
    quarter2 = Quarter(x2, y2);
    quarter3 = Quarter(x3, y3);

    // Виведення результатів
    printf("Номер координатної чверті для точки 1: %d\n", quarter1);
    printf("Номер координатної чверті для точки 2: %d\n", quarter2);
    printf("Номер координатної чверті для точки 3: %d\n", quarter3);

    return 0;
}