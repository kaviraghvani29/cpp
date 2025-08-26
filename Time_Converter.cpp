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

    //hr-sec
    cout << "Enter hours: ";
    cin >> totalHour;

    hr = totalSec * 3600;
    min = (totalSec % 3600) * 60;
    sec = totalSec % 60;

    cout << "Time is: " << hr << " hour(s), "
         << min << " minute(s), "
         << sec << " second(s)." << endl;

}