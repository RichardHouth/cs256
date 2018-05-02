//
// Created by Richard Houth on 5/1/18.
//
#include <iostream>
using namespace std;
#ifndef DAYOFYEAR_DAYOFYEAR_H
#define DAYOFYEAR_DAYOFYEAR_H

#endif //DAYOFYEAR_DAYOFYEAR_H


class DayOfYear{
private:
    int day;
    string months[12];
    int endOfMonths[13];
    static string dayMonth;
    static int restDays;
public:
    DayOfYear(int d);
    void print();
    void setEndOfMonths();
    void setMonthNames();


};