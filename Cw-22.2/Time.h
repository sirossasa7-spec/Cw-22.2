#pragma once
#include <ctime>
#include <iostream>

using namespace std;
class Time_
{
	int hour;
	int minutes;
	int seconds;
	bool format;// true = utc (24-hours),    false = am/pm (12-hours), 

public:
	Time_(); // Current local time
	Time_(int hour, int minutes, int seconds, bool format = true);
	Time_(const Time_& obj); //Визначити: чи потрібен Конструктор Копіювання?
	Time_& operator = (const Time_& obj); // Визначити: чи потрібен Оператор Присвоювання?
	~Time_(); // Визначити: чи потрібен Деструктор?

	void setHour(int hour);
	int getHour()const;
	void setMinutes(int minutes);
	int getMinutes()const;
	void setSeconds(int seconds);
	int getSeconds()const;
	void setFormat(bool format);
	bool getFormat()const;

	bool valid()const; //time check
	void tickTime(); //every tick add one second
	void untickTime(); //every tick remove one second
	void showTime()const; //show time by the format
};