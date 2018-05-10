//
// Created by Richard Houth on 5/9/18.
//

#ifndef PERSONCUSTOMER_PERSONDATA_H
#define PERSONCUSTOMER_PERSONDATA_H
#include <iostream>
using namespace std;

class PersonData{
private:
    string lastName;
    string firstName;
    string address;
    string city;
    string state;
    string zip;
    string phone;
public:
    PersonData();
    PersonData(string, string, string, string, string, string, string);
    void setLastName(string);
    string getLastName() const;
    void setFirstName(string);
    string getFirstName() const;
    void setAddress(string);
    string getAddress() const;
    void setCity(string);
    string getCity() const;
    void setState(string);
    string getState() const;
    void setZip(string);
    string getZip() const;
    void setPhone(string);
    string getPhone() const;
    void displayPersonDetails() const;
};
#endif //PERSONCUSTOMER_PERSONDATA_H
