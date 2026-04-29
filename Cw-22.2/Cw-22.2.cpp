#include "Time.h"
#include "Bus.h"
#include <iostream>
using namespace std;

int main()
{
	Time_ a; 
	/*a.setFormat(true); 
	a.showTime();
	cout << "======================================\n";*/

	/*Time_ a;
	Time_ b(23, 23, 12);
	a.showTime();
	cout << endl;
	b.showTime();
	cout << "======================================\n";
	cout << "a==b: " << boolalpha << (a == b) << endl;
	cout << "a!=b: " << boolalpha << (a != b) << endl;
	cout << "a > b: " << boolalpha << (a > b) << endl;
	cout << "a < b: " << boolalpha << (a < b) << endl;
	cout << "a >= b: " << boolalpha << (a >= b) << endl;
	cout << "a <= b: " << boolalpha << (a <= b) << endl;*/

	//a.showTime();
	//a += 2,45; 
	//a.showTime();
	//a += 5;;
	//a.showTime();
	//a += 1l;
	//a.showTime();
	//cout << "======================================\n";
	Time_ start(6, 0, 0, true);
	Time_ end(11, 0, 0, true);

	Bus b(start, end, 30, 10);
	b.showSchedule();

	return 0;
    return 0;
}
