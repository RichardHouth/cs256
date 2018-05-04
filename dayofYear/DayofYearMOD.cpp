#include <iostream>
#include <stdlib.h>
using namespace std;

class DayofYearMOD {

private:
    int  dayYear;
    int  dayMonth;
    string monthName;
public:
    DayofYearMOD(int day);

    DayofYearMOD(string month, int days);

    void print();

    DayofYearMOD &operator++();

    DayofYearMOD &operator--();

};

string month_names(int month_number) {
    string month_names[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September",
                            "October", "Novemeber", "December"};
    return month_names[month_number];

}

int month_days(int month_number){
    int month_days [] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return month_days[month_number];
}

DayofYearMOD::DayofYearMOD(int day) {
    dayYear = day;
    dayMonth = dayYear;
    int i = 0;
    while (1) {
        if(dayMonth <= month_days(i)){
            monthName = month_names(i);
            break;
        }
        else{
            dayMonth = dayMonth - month_days(i++);
            i = i % 12;
        }
    }

}

DayofYearMOD::DayofYearMOD(string month, int days) {
    for (int i  = 0; i < 12; i++){
        if(month_names(i) == month){
            if (days > 0 && days <= month_days(i)){
                monthName = month;
                dayMonth = days;
                dayYear = 0;
                for(int j = 0; j < 12; j++){
                    dayYear += month_days(i);
                    dayYear += days;

                }
            }
            else{
                cout << "Incorrect date" << endl;
            }
        }
    }
}

void DayofYearMOD::print(){
    cout << "Day " << dayYear << " would be " << monthName << " " << endl;
}

DayofYearMOD& DayofYearMOD::operator ++() {
    dayMonth = dayMonth + 1;
    dayYear = dayYear + 1;
    for (int i = 0; i < 12; i++){
        if(monthName == month_names(i)){
            if(dayMonth > month_days(i)){
                dayMonth = 1;
                monthName = month_names((i + 1) % 12);
                if( i == 11) {
                    dayYear = 1;
                }
                break;
            }
        }
    }
    return *this;

}

DayofYearMOD& DayofYearMOD::operator -- (){
    dayMonth = dayMonth - 1;
    dayYear = dayYear - 1;
    for(int i = 11; i >= 0; i--){
        if(monthName == month_names(i)){
            if(dayMonth <= 0){
                if (i == 0){
                    dayMonth = month_days(11);
                    monthName = month_names(11);
                    dayYear = 365;
                }
                else{
                    dayMonth = month_days(i - 1);
                    monthName = month_names(i - 1);
                }
            }
        }break;
    }
    return *this;
}

int main() {
    DayofYearMOD dof(2);
    DayofYearMOD dof2(32);
    DayofYearMOD dof3(365);
    cout << endl;
    cout << "Given day and the converted day of the month " << endl;
    dof.print();
    dof2.print();
    dof3.print();

    cout << "Given month and converted day of month" << endl;
    DayofYearMOD dof4("april", 27);
    DayofYearMOD dof5("February", 1);
    DayofYearMOD dof6("December", 31);
    cout << endl;
    dof4.print();
    dof5.print();
    dof6.print();
    cout << endl;

    cout << "\nAfter post increment " << endl;
    dof5.print();
    cout << "\nAfter post increment " << endl;
    dof6.print();

    cout << "\nNow we pre increment" << endl;
    dof2 = ++dof5;
    cout << endl;
    dof2.print();
    dof5.print();
    dof = -- dof4;
    cout << "\nAfter decrement" << endl;
    dof.print();
    dof4.print();

    return 0;
}

