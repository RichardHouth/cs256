//
// Created by Richard Houth on 5/9/18.
//

#include "CustomerData.h"
#include <iostream>
using namespace std;

CustomerData::CustomerData() : PersonData() {
    customerNumber = 0;
    mailingList = false;
}

CustomerData::CustomerData(string newLastName, string newFirstName, string newAddress, string newCity, string newState, string newZip, string newPhone, int newCustomerNumber, bool newMailingList)
    :PersonData(newLastName, newFirstName, newAddress, newCity, newState, newZip, newPhone){
        customerNumber = newCustomerNumber;
        mailingList = newMailingList;
    }

    void CustomerData::setCustomerNumber(int newCustomerNumber) {
    customerNumber = newCustomerNumber;
}

int CustomerData::getCustomerNumber() const {
    return customerNumber;
}

void CustomerData::setMailingList(bool newMailingList) {
    mailingList = newMailingList;
}

bool CustomerData::getMailingList() const {
    return mailingList;
}

void CustomerData::displayCustomer() const {
    cout << "Customer number: " << getCustomerNumber() << endl;
    displayPersonDetails();
    cout << "Mailing status: ";
    if(getMailingList()){
        cout << "true" << endl << endl;
    }
    else {
        cout << "false" << endl << endl;
    }
}