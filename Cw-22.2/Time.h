#pragma once
#include <iostream>

class Time
{
    int hour;
    int minutes;
    int seconds;
    bool format; // true = 24h, false = 12h

public:
    Time();
    Time(int hour, int minutes, int seconds, bool format = true);
    Time(const Time& obj);
    Time& operator=(const Time& obj);
    ~Time();

    void setHour(int hour);
    int getHour() const;

    void setMinutes(int minutes);
    int getMinutes() const;

    void setSeconds(int seconds);
    int getSeconds() const;

    void setFormat(bool format);
    bool getFormat() const;

    bool valid() const;
    void tickTime();
    void untickTime();
    void showTime() const;

    // operators
    bool operator==(const Time& obj) const;
    bool operator!=(const Time& obj) const;
    bool operator>(const Time& obj) const;
    bool operator<(const Time& obj) const;
    bool operator>=(const Time& obj) const;
    bool operator<=(const Time& obj) const;
    //--------- Assignment operators ---------	
    Time& operator += (float s);	// add seconds
    Time& operator -= (float s);
    Time& operator += (int m);		// add minutes
    Time& operator -= (int m);
    Time& operator += (long h);	// add hours
    Time& operator -= (long h);
    //--------- Arithmetic operators ---------
    Time operator + (float s)const&;	// add seconds 
    Time operator - (float s)const&;
    Time operator + (int m)const&; // add minutes 
    Time operator - (int m)const&;
    Time operator + (long h)const&; // add hours 
    Time operator - (long h)const&;
};

