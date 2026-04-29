#include "Time.h"
#include <iostream>
using namespace std;

class Bus {
private:
    Time_ start;
    Time_ end;
    int travelMinutes;
    int restMinutes;

public:
    Bus(Time_ s, Time_ e, int travel, int rest)
        : start(s), end(e), travelMinutes(travel), restMinutes(rest) {
    }

    void showSchedule() {
        Time_ t = start;

        bool direction = true; 

        cout << "Schedule:\n";

        while (t <= end) {

            Time_ depart = t;

            
            Time_ arrive = depart;
            arrive += travelMinutes;

            if (arrive > end) break;

            cout << depart << " -> " << arrive;

            
            arrive += restMinutes;
            t = arrive;

            cout << endl;

            direction = !direction;
        }
    }
};