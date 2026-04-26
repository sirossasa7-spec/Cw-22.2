#include "Time.h"
#include <iostream>
using namespace std;

int main()
{
    //// 1. Текущее время
    //Time t1;
    //cout << "Current time: ";
    //t1.showTime();

    //// 2. Задание времени вручную
    //Time t2(13, 45, 30);
    //cout << "Manual time: ";
    //t2.showTime();

    //// 3. Формат 12 часов
    //t2.setFormat(false);
    //cout << "12-hour format: ";
    //t2.showTime();

    //// 4. Проверка tick (+1 секунда)
    //t2.tickTime();
    //cout << "After tick: ";
    //t2.showTime();

    //// 5. Проверка untick (-1 секунда)
    //t2.untickTime();
    //cout << "After untick: ";
    //t2.showTime();

    //// 6. Конструктор копирования
    //Time t3 = t2;
    //cout << "Copied time: ";
    //t3.showTime();

    //// 7. Оператор присваивания
    //Time t4;
    //t4 = t2;
    //cout << "Assigned time: ";
    //t4.showTime();

    //// 8. Проверка некорректного времени
    //Time t5(25, 70, 90);
    //cout << "Invalid time corrected to: ";
    //t5.showTime();

    //// 9. Comparison operators
    //Time a(10, 20, 30);
    //Time b(12, 10, 15);

    //cout << "\nComparisons:\n";
    //cout << (a == b) << endl; // 0
    //cout << (a != b) << endl; // 1
    //cout << (a > b) << endl;  // 0
    //cout << (a < b) << endl;  // 1
    //cout << (a >= b) << endl; // 0
    //cout << (a <= b) << endl; // 1
    // Базовое время
    Time t(10, 30, 0);
    cout << "Start: ";
    t.showTime();

    // + float (секунды)
    t += 10.0f;
    cout << "+10 sec: ";
    t.showTime();

    // - float (секунды)
    t -= 5.0f;
    cout << "-5 sec: ";
    t.showTime();

    // + minutes
    t += 2;
    cout << "+2 min: ";
    t.showTime();

    // - minutes
    t -= 1;
    cout << "-1 min: ";
    t.showTime();

    // + hours
    t += 1L;
    cout << "+1 hour: ";
    t.showTime();

    // - hours
    t -= 1L;
    cout << "-1 hour: ";
    t.showTime();

    // Проверка отрицательного времени / перехода через сутки
    Time t2(0, 0, 5);
    cout << "\nEdge case start: ";
    t2.showTime();

    t2 -= 10.0f;
    cout << "After -10 sec: ";
    t2.showTime();

    return 0;
}
