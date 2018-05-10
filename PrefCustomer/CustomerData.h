//
// Created by Richard Houth on 5/9/18.
//

#ifndef PERSONCUSTOMER_CUSTOMERDATA_H
#define PERSONCUSTOMER_CUSTOMERDATA_H
#include "PersonData.h"
#include <iostream>
using namespace std;

class CustomerData: public PersonData {
private:
    int customerNumber;
    bool mailingList;
public:
    CustomerData();
    CustomerData(string, string, string, string, string, string, string, int, bool);
    void setCustomerNumber(int);
    int getCustomerNumber() const;
    void setMailingList(bool);
    bool getMailingList() const;
    void displayCustomer() const;
};
#endif //PERSONCUSTOMER_CUSTOMERDATA_H
