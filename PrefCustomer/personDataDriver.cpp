//Richard Houth
//CS 256
#include <iostream>
#include "CustomerData.h"

bool isThere(int);

const int maxCustomers = 10;
CustomerData customers[maxCustomers];

int count = 0;

int main() {
    string IName, FName, addr, ct, st, zp, phn, wish;
    int custNum;
    bool mailList;
    char choice;

    do {
        cout << "Enter customer number: ";
        cin >> custNum;
        if (!isThere(custNum)) {
            cout << "Enter last name: ";
            cin >> IName;
            cout << "Enter address: ";
            cin >> addr;
            cout << "Enter city: ";
            cin >> ct;
            cout << "Enter state: ";
            cin >> st;
            cout << "Enter zip: ";
            cin >> zp;
            cout << "Enter phone number: ";
            cin >> phn;
            cout << "Enter wishing on mailing list";
            cin >> wish;
            if (wish == "yes") {
                mailList = true;
            } else {
                mailList = false;
            }
            CustomerData customer(IName, FName, addr, ct, st, zp, phn, custNum, mailList);
            customers[::count] = customer;
            ::count++;
        } else {
            cout << "This number is already on list. " << endl;
        }
        cout << "Repeat for another customer? (Y/N)";
        cin >> choice;
        cout << endl;
    } while ((choice == 'y' || choice == 'Y') && ::count<maxCustomers);

    cout << "Details of customers: " << endl;
    for (int i = 0; i < ::count; i++) {
        customers[i].displayCustomer();
    }
    return 0;
}

bool isThere(int number) {
    for (int i = 0; i < ::count; i++) {
        if (customers[i].getCustomerNumber() == number) {
            return true;
        }
    }
    return false;
}

