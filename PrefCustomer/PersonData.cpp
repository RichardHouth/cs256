//
// Created by Richard Houth on 5/9/18.
//

#include "PersonData.h"
#include <iostream>
using namespace std;

PersonData::PersonData() {
    lastName = "";
    firstName = "";
    address = "";
    city = "";
    state = "";
    zip = "";
    phone = "";

}

PersonData::PersonData(string newLastName, string newFirstName, string newAddress, string newCity, string newState, string newZip, string newPhone) {
    lastName = newLastName;
    firstName = newFirstName;
    address = newAddress;
    city = newCity;
    state = newState;
    zip = newZip;
    phone = newPhone;
}

void PersonData::setLastName(string newLastName) {
    lastName = newLastName;
}

string PersonData::getLastName() const {
    return lastName;
}

void PersonData::setFirstName(string newFirstName) {
    firstName = newFirstName;
}

string PersonData::getFirstName() const {
    return firstName;
}

void PersonData::setAddress(string newAddress) {
    address = newAddress;
}

string PersonData::getAddress() const {
    return address;
}

void PersonData::setCity(string newCity) {
    city = newCity;
}

string PersonData::getCity() const {
    return city;
}

void PersonData::setState(string newState) {
    state = newState;
}

string PersonData::getState() const {
    return state;
}

void PersonData::setZip(string newZip) {
    zip = newZip;
}

string PersonData::getZip() const {
    return zip;
}

void PersonData::setPhone(string newPhone) {
    phone = newPhone;
}

string PersonData::getPhone() const {
    return phone;
}

void PersonData::displayPersonDetails() const {
    cout << "Details of customers " << endl;
    cout <<"Last name: " << getLastName() << endl;
    cout <<"First name: " << getFirstName() << endl;
    cout <<"Address: " << getAddress() << endl;
    cout <<"City: " << getCity() << endl;
    cout <<"State: " << getState() << endl;
    cout <<"Zip: " << getZip() << endl;
    cout <<"Phone: " << getPhone() << endl;
}