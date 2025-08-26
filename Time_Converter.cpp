#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int totalSec;
    int totalHour;
    int hr, min, sec;

    //sec-hr
    cout << "Enter total seconds: ";
    cin >> totalSec;

    hr = totalSec / 3600;
    min = (totalSec % 3600) / 60;
    sec = totalSec % 60;

    cout << "Time is: " << hr << " hour "
        << min << " minute "
        << sec << " second " << endl;

    //hr-sec
    cout << "Enter hours: ";
    cin >> hr;
    cout << "Enter minutes: ";
    cin >> min;
    cout << "Enter seconds: ";
    cin >> sec;
    totalSec = hr * 3600 + min * 60 + sec;

    cout << "Time is: " << totalSec << endl;
}