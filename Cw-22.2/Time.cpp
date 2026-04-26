#include "Time.h"
#include <ctime>

using namespace std;

// Конструктор по умолчанию
Time::Time()
{
    time_t now = time(0);
    tm local{};

#ifdef _WIN32
    localtime_s(&local, &now);
#else
    local = *localtime(&now);
#endif

    hour = local.tm_hour;
    minutes = local.tm_min;
    seconds = local.tm_sec;
    format = true;
}

Time::Time(int h, int m, int s, bool f)
{
    hour = h;
    minutes = m;
    seconds = s;
    format = f;

    if (!valid())
        hour = minutes = seconds = 0;
}

Time::Time(const Time& obj)
{
    hour = obj.hour;
    minutes = obj.minutes;
    seconds = obj.seconds;
    format = obj.format;
}

Time& Time::operator=(const Time& obj)
{
    if (this != &obj)
    {
        hour = obj.hour;
        minutes = obj.minutes;
        seconds = obj.seconds;
        format = obj.format;
    }
    return *this;
}

Time::~Time() {}

// SET / GET
void Time::setHour(int h) { hour = h; }
int Time::getHour() const { return hour; }

void Time::setMinutes(int m) { minutes = m; }
int Time::getMinutes() const { return minutes; }

void Time::setSeconds(int s) { seconds = s; }
int Time::getSeconds() const { return seconds; }

void Time::setFormat(bool f) { format = f; }
bool Time::getFormat() const { return format; }

// Проверка
bool Time::valid() const
{
    return (hour >= 0 && hour < 24 &&
        minutes >= 0 && minutes < 60 &&
        seconds >= 0 && seconds < 60);
}

// +1 секунда
void Time::tickTime()
{
    seconds++;
    if (seconds >= 60)
    {
        seconds = 0;
        minutes++;
        if (minutes >= 60)
        {
            minutes = 0;
            hour++;
            if (hour >= 24)
                hour = 0;
        }
    }
}

// -1 секунда
void Time::untickTime()
{
    seconds--;
    if (seconds < 0)
    {
        seconds = 59;
        minutes--;
        if (minutes < 0)
        {
            minutes = 59;
            hour--;
            if (hour < 0)
                hour = 23;
        }
    }
}

// Вывод
void Time::showTime() const
{
    if (format)
    {
        cout << (hour < 10 ? "0" : "") << hour << ":"
            << (minutes < 10 ? "0" : "") << minutes << ":"
            << (seconds < 10 ? "0" : "") << seconds << endl;
    }
    else
    {
        int h = hour % 12;
        if (h == 0) h = 12;

        cout << (h < 10 ? "0" : "") << h << ":"
            << (minutes < 10 ? "0" : "") << minutes << ":"
            << (seconds < 10 ? "0" : "") << seconds
            << (hour < 12 ? " AM" : " PM") << endl;
    }
}

// ===== ОПЕРАТОРЫ (ВНЕ showTime!) =====

bool Time::operator==(const Time& obj) const
{
    return hour == obj.hour &&
        minutes == obj.minutes &&
        seconds == obj.seconds;
}

bool Time::operator!=(const Time& obj) const
{
    return !(*this == obj);
}

bool Time::operator>(const Time& obj) const
{
    if (hour != obj.hour)
        return hour > obj.hour;

    if (minutes != obj.minutes)
        return minutes > obj.minutes;

    return seconds > obj.seconds;
}

bool Time::operator<(const Time& obj) const
{
    return obj > *this;
}

bool Time::operator>=(const Time& obj) const
{
    return !(*this < obj);
}

bool Time::operator<=(const Time& obj) const
{
    return !(*this > obj);
}

Time& Time::operator+=(float s)
{
    for (int i = 0; i < (int)s; i++)
        tickTime();

    return *this;
}

Time& Time::operator-=(float s)
{
    for (int i = 0; i < (int)s; i++)
        untickTime();

    return *this;
}

Time& Time::operator+=(int m)
{
    for (int i = 0; i < m; i++)
        for (int j = 0; j < 60; j++)
            tickTime();

    return *this;
}

Time& Time::operator-=(int m)
{
    for (int i = 0; i < m; i++)
        for (int j = 0; j < 60; j++)
            untickTime();

    return *this;
}

Time& Time::operator+=(long h)
{
    for (int i = 0; i < h; i++)
        for (int j = 0; j < 3600; j++)
            tickTime();

    return *this;
}

Time& Time::operator-=(long h)
{
    for (int i = 0; i < h; i++)
        for (int j = 0; j < 3600; j++)
            untickTime();

    return *this;
}
