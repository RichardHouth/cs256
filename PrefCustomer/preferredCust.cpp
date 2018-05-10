//Richard Houth
//CS 256 
#include <iostream>
#include <string>
using namespace std;

class PersonData{
private:
    string lastName;
    string firstName;
    string address;
    string City;
    string State;
    long int Zip;
    long int phone;
public:
    PersonData(){
        lastName = " ";
        firstName = " ";
        address = " ";
        City = " ";
        State = " ";
        Zip = 0;
        phone = 0;
    }
    void setLastName(string);
    void setFirstName(string);
    void setAddress(string);
    void setCity(string);
    void setState(string);
    void setZip(long);
    void setPhone(long);
    string getLastName();
    string getFirstName();
    string getAddress();
    string getCity();
    string getState();
    long getZip();
    long getPhone();
};

void PersonData::setLastName(string lName) {
    lastName = lName;
}

void PersonData::setFirstName(string fName) {
    firstName = fName;
}

void PersonData::setAddress(string addr) {
    address = addr;
}

void PersonData:: setCity(string city){
    City = city;
}

void PersonData::setState(string state) {
    State = state;
}

void PersonData::setZip(long z) {
    Zip = z;
}

void PersonData::setPhone(long phno) {
    phone = phno;
}

string PersonData::getLastName() {
    return lastName;
}

string PersonData::getFirstName() {
    return firstName;
}

string PersonData::getAddress() {
    return address;
}

string PersonData::getCity() {
    return City;
}

string PersonData::getState() {
    return State;
}

long PersonData::getZip() {
    return Zip;
}

long PersonData::getPhone() {
    return phone;
}

class CustomerData: public PersonData{
private:
    int customerNumber;
    bool mailingList;
public:
    CustomerData(){
        customerNumber = 0;
        mailingList = false;
    }
    void setCustomerNumber(int);
    void setMailingList(bool);
    int getCustomerNumber();
    bool getMailingList();
};

void CustomerData::setCustomerNumber(int num) {
    customerNumber = num;
}

void CustomerData::setMailingList(bool list) {
    mailingList = list;
}

int CustomerData::getCustomerNumber() {
    return customerNumber;
}

bool CustomerData::getMailingList() {
    return mailingList;
}

class PreferredCustomer: public CustomerData
{
private:
    double purchaseAmount;
    double discountLabel;
public:
    PreferredCustomer() {
        purchaseAmount = 0;
        discountLabel = 0;
    }
    void setPurchaseAmount();
    void setDiscountLabel();
    double getPurchaseAmount();
    double getDiscountLabel();
};

void PreferredCustomer::setPurchaseAmount() {
    double amount;
    cout << "Enter customer spending amount:";
    cin >> amount;
    purchaseAmount = amount;
}

void PreferredCustomer::setDiscountLabel() {
    if (purchaseAmount >= 500 && purchaseAmount < 1000){
        discountLabel = 5;
    }
    else if(purchaseAmount >= 1000 && purchaseAmount < 1500){
        discountLabel = 6;
    }
    else if(purchaseAmount >= 1500 && purchaseAmount < 2000){
        discountLabel = 7;
    }
    else if(purchaseAmount >= 2000){
        discountLabel = 10;
    }
}

double PreferredCustomer::getPurchaseAmount() {
    return purchaseAmount;
}

double PreferredCustomer::getDiscountLabel() {
    return discountLabel;
}

int main() {
    PreferredCustomer cust1;
    string name, addr, city, state;
    int custId;
    long Zcode, phno;

    cout << "Enter customer first name: ";
    cin >> name;
    cust1.setFirstName(name);
    cout << "Enter customer last name: ";
    cin >> name;
    cust1.getLastName();
    cout << "Enter address: ";
    cin >> addr;
    fflush(stdin);
    cust1.setAddress(addr);
    cout << "Enter city name: ";
    cin >> city;
    cust1.setCity(city);
    fflush(stdin);
    cout << "Enter state name: ";
    cin >> state;
    cust1.setState(state);
    cout << "Enter Zip code: ";
    cin >> Zcode;
    cust1.setZip(Zcode);
    cout << "Enter phone number: ";
    cin >> phno;
    cust1.setCustomerNumber(custId);
    cust1.setMailingList(true);

    cust1.setPurchaseAmount();
    cust1.setDiscountLabel();

    cout <<"\n\n*** Customer Data ***" << endl;
    cout <<"Customer first name: " << cust1.getFirstName() << endl;
    cout << "Customer last name: " << cust1.getLastName() << endl;
    cout << "Customer number: " << cust1.getCustomerNumber() << endl;
    cout << "Customer address: " << cust1.getAddress() << endl;
    cout << "City name: " << cust1.getCity() << endl;
    cout << "State name: " << cust1.getState() << endl;
    cout << "Zip code: " << cust1.getZip() << endl;
    cout << "phone number: " << cust1.getPhone() << endl;
    cout << "Mailing list: " << cust1.getMailingList() << endl;
    cout << "Customer purchase amount: " << cust1.getPurchaseAmount() << endl;
    cout << "Customer discount on every item: " << cust1.getDiscountLabel() << "%\n" << endl;
    return 0;

}
