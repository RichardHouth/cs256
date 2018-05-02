#include <iostream>
#include "DayofYear.h"
using namespace std;


int main() {

    int dayNumber;

    cout <<"Please enter a day number from 1 to 365:";
    cin >> dayNumber;

    while (dayNumber < 1 || dayNumber > 365) {
        cout <<"Invalid entry. Enter another number:";
        cin >> dayNumber;
    }

    DayOfYear d(dayNumber);
    d.setEndOfMonths();
    d.setMonthNames();
    d.print();

    system("pause");


    return 0;
}