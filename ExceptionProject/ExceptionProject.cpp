//Richard Houth
//CS 256
#include <iostream>
#include <string>

using namespace std;

class Employee {
private:
    string eName;
    int eNumber;
    string HireDate;
public:
    Employee() {
        eName = " ";
        eNumber = 0;
        HireDate = " ";
    }

    Employee(string name, int number, string date) {
        eName = name;
        eNumber = number;
        HireDate = date;
    }

    class InvalidEmployeeNumber {

    };

    void setEmpName(string);

    void setEmpNumber(int);

    void setHireDate(string);

    string getEmpName();

    int getEmpNumber();

    string getHireDate();
};

void Employee::setEmpName(string str) {
    eName = str;
}

void Employee::setEmpNumber(int num) {
    if (num < 0 || num > 9999) {
        throw InvalidEmployeeNumber();
    } else {
        eNumber = num;
    }
}

void Employee::setHireDate(string date) {
    HireDate = date;
}

string Employee::getEmpName() {
    return eName;
}

int Employee::getEmpNumber() {
    return eNumber;
}

string Employee::getHireDate() {
    return HireDate;
}

class ProductionWorker : public Employee {
private:
    int Shift;
    double HourlyPay;
public:
    ProductionWorker() {
        Shift = 0;
        HourlyPay = 0.0;
    }

    ProductionWorker(int sh, double pay) {
        Shift = sh;
        HourlyPay = pay;
    }

    class InvalidShift {
    };

    class InvalidPayRate {
    };

    void setShift(int);

    void setHourlyPay(double);

    int getShift();

    double getHourlyPay();
};

void ProductionWorker::setShift(int sh) {
    if (sh < 0 || sh > 2) {
        throw InvalidShift();
    } else {
        Shift = sh;
    }
}

void ProductionWorker::setHourlyPay(double pay) {
    if (pay < 1) {
        throw InvalidPayRate();
    } else {
        HourlyPay = pay;
    }
}

int ProductionWorker::getShift() {
    return Shift;
}

double ProductionWorker::getHourlyPay() {
    return HourlyPay;
}

int main() {
    int shift;
    double pay;

    cout << "Enter 1 for day shift, 2 for night shift " << endl;
    cout << "Enter desired shift:  ";
    cin >> shift;

    cout << "Enter hourly pay: ";
    cin >> pay;

    ProductionWorker worker1(0, 0);
    worker1.setEmpName("Richard Houth");
    worker1.setHireDate("Novemeber 13th");
    try {
        worker1.setEmpNumber(9561);
        worker1.setShift(shift);
        worker1.setHourlyPay(pay);
    }
    catch (Employee::InvalidEmployeeNumber) {
        cout << "Invalid employee number " << endl;
        return 0;
    }
    catch (ProductionWorker::InvalidShift) {
        cout << "Invalid shift " << endl;
        return 0;
    }
    catch (ProductionWorker::InvalidPayRate) {
        cout << "Invalid pay rate" << endl;
        return 0;
    }

    cout << "Here are the employee's details: " << endl << endl;
    cout << "Employee name: " << worker1.getEmpName() << endl;
    cout << "Employee number: " << worker1.getEmpNumber() << endl;
    cout << "Employee hire date: " << worker1.getHireDate() << endl;
    cout << "Employee shift: " << worker1.getShift() << endl;
    cout << "Employee HourlyPay: $" << worker1.getHourlyPay() << endl;

    return 0;
}