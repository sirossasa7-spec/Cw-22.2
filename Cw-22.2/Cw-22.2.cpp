#include "Time.h"
#include <iostream>
using namespace std;

int main()
{
    // 1. Текущее время
    Time t1;
    cout << "Current time: ";
    t1.showTime();

    // 2. Задание времени вручную
    Time t2(13, 45, 30);
    cout << "Manual time: ";
    t2.showTime();

    // 3. Формат 12 часов
    t2.setFormat(false);
    cout << "12-hour format: ";
    t2.showTime();

    // 4. Проверка tick (+1 секунда)
    t2.tickTime();
    cout << "After tick: ";
    t2.showTime();

    // 5. Проверка untick (-1 секунда)
    t2.untickTime();
    cout << "After untick: ";
    t2.showTime();

    // 6. Конструктор копирования
    Time t3 = t2;
    cout << "Copied time: ";
    t3.showTime();

    // 7. Оператор присваивания
    Time t4;
    t4 = t2;
    cout << "Assigned time: ";
    t4.showTime();

    // 8. Проверка некорректного времени
    Time t5(25, 70, 90);
    cout << "Invalid time corrected to: ";
    t5.showTime();

    return 0;
}
