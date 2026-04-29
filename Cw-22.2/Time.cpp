#include "Time.h"
#include <iostream>
using namespace std;
Time_::Time_()
{
	tm* info = new tm;
	auto curent = time(0);	
	localtime_s(info, &curent);
	hour = info->tm_hour;
	minutes = info->tm_min;
	seconds = info->tm_sec;
	format = true;
	delete info;
}

Time_::Time_(int hour, int minutes, int seconds, bool format)
{
	this->hour = hour;
	this-> minutes = minutes;
	this-> seconds = seconds;
	this-> format = format;
}

Time_::Time_(const Time_& obj)
{
	hour = obj.hour;
	minutes = obj.minutes;
	seconds = obj.seconds;
	format = obj.format;
}


Time_& Time_::operator=(const Time_& obj)
{
	if (this == &obj) {
		hour = obj.hour;
		minutes = obj.minutes;
		seconds = obj.seconds;
		format = obj.format;
	}return *this;
}

Time_::~Time_()
{

}

void Time_::setHour(int hour)
{
	if (hour >= 0 && hour < 24)
		this->hour = hour;
}

int Time_::getHour() const
{
	return hour;
}

void Time_::setMinutes(int minutes)
{
	if (minutes >= 0 && minutes < 60)
		this->minutes = minutes;
}

int Time_::getMinutes() const
{
	return minutes;
}

void Time_::setSeconds(int seconds)
{
	if (seconds >= 0 && seconds < 60)
		this->seconds = seconds;
}

int Time_::getSeconds() const
{
	return seconds;
}

void Time_::setFormat(bool format)
{
	this->format = format;
}

bool Time_::getFormat() const
{
	return format;
}

bool Time_::valid() const
{
	return (hour >= 0 && hour < 24) && (minutes >= 0 && minutes < 60) && (seconds >= 0 && seconds < 60);
}

void Time_::tickTime()
{
	seconds++;
	if (seconds >= 60) {
		seconds = 0;
		minutes++;
	}
	if (minutes >= 60) {
		minutes = 0;
		hour++;
	}
	if (hour >= 24) {
		hour = 0;
	}
}

void Time_::untickTime()
{
	seconds--;
	if (seconds < 0) {
		seconds = 59;
		minutes--;
	}
	if (minutes < 0) {
		minutes = 59;
		hour--;
	}
	if (hour < 0) {
		hour = 23;
	}
}

void Time_::showTime() const
{
	if (format) // 24-hour
	{
		cout << (hour < 10 ? "0" : "") << hour << ":"
			<< (minutes < 10 ? "0" : "") << minutes << ":"
			<< (seconds < 10 ? "0" : "") << seconds << endl;
	}
	else // 12-hour
	{
		int displayHour = hour % 12;
		if (displayHour == 0) displayHour = 12;

		cout << (displayHour < 10 ? "0" : "") << displayHour << ":"
			<< (minutes < 10 ? "0" : "") << minutes << ":"
			<< (seconds < 10 ? "0" : "") << seconds
			<< (hour < 12 ? " AM" : " PM") << endl;
	}
}

bool Time_::operator==(const Time_& obj) const&
{
	return this->hour == obj.hour && this->minutes == obj.minutes && this->seconds == obj.seconds && this->format == obj.format;
}

bool Time_::operator!=(const Time_& obj) const&
{
	return !(*this == obj);
}

bool Time_::operator>(const Time_& obj) const&
{
	if (hour > obj.hour) return true;
	if (hour == obj.hour && minutes > obj.minutes) return true;
	if (hour == obj.hour && minutes == obj.minutes && seconds > obj.seconds) return true;
	return false;
}

bool Time_::operator<(const Time_& obj) const&
{
	return !(*this > obj) && !(*this == obj);
}

bool Time_::operator>=(const Time_& obj) const&
{
	return (*this > obj) || (*this == obj);
}

bool Time_::operator<=(const Time_& obj) const&
{
	return !(*this > obj);
}

Time_& Time_::operator+=(float s)
{
	for (int i = 0; i < s; i++) {
		tickTime();
	}
	return *this;
}

Time_& Time_::operator-=(float s)
{
	for (int i = 0; i < s; i++) {
		untickTime();
	}
	return *this;
}

Time_& Time_::operator+=(int m)
{
	this->minutes += m;
	while (this->minutes >= 60) {
		this->minutes -= 60;
		this->hour++;
	}
		return *this;
}

Time_& Time_::operator-=(int m)
{
	this->minutes -= m;
	while (this->minutes < 0) {
		this->minutes += 60;
		this->hour--;
	}
	return *this;
}

Time_& Time_::operator+=(long h)
{
	this->hour += h;
	while (this->hour >= 24) {
		this->hour -= 24;
	}
	return *this;
}

Time_& Time_::operator-=(long h)
{
	this->hour -= h;
	while (this->hour < 0) {
		this->hour += 24;
	}
	return *this;
}

Time_ Time_::operator+(float s) const&
{
	Time_ tmp = *this;
	tmp += s;
	return tmp;
}

Time_ Time_::operator-(float s) const&
{
	Time_ tmp = *this;
	tmp -= s;
	return tmp;
}

Time_ Time_::operator+(int m) const&
{
	Time_ tmp = *this;
	tmp += m;
	return tmp;
}

Time_ Time_::operator-(int m) const&
{
	Time_ tmp = *this;
	tmp += m;
	return tmp;
}

Time_ Time_::operator+(long h) const&
{
	Time_ tmp = *this;
	tmp += h;
	return tmp;
}

Time_ Time_::operator-(long h) const&
{
	Time_ tmp = *this;
	tmp += h;
	return tmp;
}

