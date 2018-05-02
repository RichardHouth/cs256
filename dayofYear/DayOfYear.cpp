//
// Created by Richard Houth on 5/1/18.
//

#include "DayofYear.h"
#include <iostream>
using namespace std;

string DayOfYear::dayMonth = "";
int DayOfYear::restDays = 0;

DayOfYear::DayOfYear(int d) {
    day = d;
}

void DayOfYear::setEndOfMonths() {
    endOfMonths[0] = 0;
    endOfMonths[1] = 31;
    endOfMonths[2] = 59;
    endOfMonths[3] = 90;
    endOfMonths[4] = 120;
    endOfMonths[5] = 151;
    endOfMonths[6] = 181;
    endOfMonths[7] = 212;
    endOfMonths[8] = 243;
    endOfMonths[9] = 273;
    endOfMonths[10] = 304;
    endOfMonths[11] = 334;
    endOfMonths[12] = 365;

}

void DayOfYear::setMonthNames() {
    months[0] = "January";
    months[1] = "February";
    months[2] = "March";
    months[3] = "April";
    months[4] = "May";
    months[5] = "June";
    months[6] = "July";
    months[7] = "August";
    months[8] = "September";
    months[9] = "October";
    months[10] = "November";
    months[11] = "December";
}

void DayOfYear::print() {
    int month = 0;
    while (endOfMonths[month] < day) {
        month++;
    }

        dayMonth += months[month - 1];
        restDays += day - endOfMonths[month - 1];
        cout << "\nThe corresponding day is: " << dayMonth << " " << restDays << endl;


}

