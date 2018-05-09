//Richard Houth
//CS 256
#include<iostream>
#include<cmath>
#include<string>

using namespace std;


class ParkedCar {
private:
    string carMake;
    string carModel;
    string carColor;
    string carLicenseNum;
    int minutesParked;

public:
    ParkedCar() {
        carMake = "";
        carModel = "";
        carColor = "";
        carLicenseNum = "";
        minutesParked = 0;
    }

    ParkedCar(string cMake, string cModel, string cColor, string cLicenseNum, int cNumMinParked) {
        carMake = cMake;
        carModel = cModel;
        carColor = cColor;
        carLicenseNum = cLicenseNum;
        minutesParked = cNumMinParked;
    }

    int getParkedMinutes() const {
        return minutesParked;
    }

    void print() {
        cout << "- Car -\n" << endl;
        cout << "Make: " << carMake << endl;
        cout << "Model: " << carModel << endl;
        cout << "Color: " << carColor << endl;
        cout << "License Number: " << carLicenseNum << endl;
    }
};

class ParkingMeter {
private:
    int purchasedParkingMins;

public:
    ParkingMeter() {
        purchasedParkingMins = 0;
    }

    ParkingMeter(int purchasedMinutes) {
        purchasedParkingMins = purchasedMinutes;
    }

    int getPurchasedParkingMins() const {
        return purchasedParkingMins;
    }

    void print() {
        cout << "- Meter -\n" << endl;
        cout << "Number of minutes purchased : " << purchasedParkingMins << endl;
    }
};


class PoliceOfficer {
private:
    string lastName;
    string firstName;
    string badgeNum;

public:
    PoliceOfficer() {
        lastName = "";
        firstName = "";
        badgeNum = "";
    }

    PoliceOfficer(string lName, string fName, string bNum) {
        lastName = lName;
        firstName = fName;
        badgeNum = bNum;
    }

    bool isTicketNeccessary(ParkedCar &c, ParkingMeter &m) {
        if ((m.getPurchasedParkingMins() - c.getParkedMinutes()) < 0) {
            return true;
        } else {
            return false;
        }
    }

    void print() {
        cout << "- Police Officer -\n" << endl;
        cout << "First Name: " << firstName << endl;
        cout << "Last Name: " << lastName << endl;
        cout << "Badge Number: " << badgeNum << endl;
    }
};

class ParkingTicket {
private:
    ParkedCar car;
    ParkingMeter meter;
    PoliceOfficer officer;
    int fineAmount;

public:
    ParkingTicket(ParkedCar &carT, ParkingMeter &meterT, PoliceOfficer &officerT) {
        car = carT;
        meter = meterT;
        officer = officerT;
        fineAmount = calcFineAmount();
    }

    int calcFineAmount() {
        return (25 + 10 * (ceil((car.getParkedMinutes() - meter.getPurchasedParkingMins()) / 60.0) - 1));
    }

    void print() {
        cout << "\n\n TICKET INFORMATION " << endl;
        cout << "-------------------------------------" << endl;
        car.print();
        cout << "-------------------------------------" << endl;
        officer.print();
        cout << "-------------------------------------" << endl;
        cout << "- Fine -\n\n" << "Amount: $" << fineAmount << endl;
        cout << "-------------------------------------" << endl;
    }
};


int main() {
    string carMake;
    string carModel;
    string carColor;
    string carLicenseNum;
    int numMinutesParked;
    int purchasedParkingMins;
    string lastName;
    string firstName;
    string badgeNum;

    cout << "Enter information below.\n" << endl;
    cout << "CAR:\n" << endl;
    cout << "Make: ";
    cin >> carMake;
    cout << "Model: ";
    cin >> carModel;
    cout << "Color: ";
    cin >> carColor;
    cout << "License Number: ";
    cin >> carLicenseNum;

    do {
        cout << "Number of minutes car has been parked: ";
        cin >> numMinutesParked;
    } while (numMinutesParked < 0);

    ParkedCar car1(carMake, carModel, carColor, carLicenseNum, numMinutesParked);

    cout << "\nMETER:\n" << endl;

    do {
        cout << "Number of minutes purchased: ";
        cin >> purchasedParkingMins;
    } while (purchasedParkingMins < 0);

    ParkingMeter meter1(purchasedParkingMins);

    cout << "\nPOLICE OFFICER:\n" << endl;
    cout << "First Name: ";
    cin >> firstName;
    cout << "Last Name: ";
    cin >> lastName;
    cout << "Badge Number: ";
    cin >> badgeNum;

    PoliceOfficer officer1(lastName, firstName, badgeNum);

    if (officer1.isTicketNeccessary(car1, meter1) == true) {
        ParkingTicket ticket1(car1, meter1, officer1);
        ticket1.print();
    } else {
        cout << "\n* No ticket issued. *" << endl;
    }

    return 0;
}