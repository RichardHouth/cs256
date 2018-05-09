//Richard Houth
//CS 256
#include<iostream>
#include<string>

using namespace std;


class Ship {


private:

    string shipName;
    string shipBuilt;

public:


    Ship(string name, string yearBuilt) {

        shipName = name;

        shipBuilt = yearBuilt;

    }


    string getName() {

        return shipName;

    }

    string getBuild() {

        return shipBuilt;

    }


    virtual void print() {


        cout << "Ship's Name:" << getName() << "\nYear built:" << getBuild() << endl;

    }

};


class CruiseShip : public Ship {

private:
    int passengers;

public:


    CruiseShip(string n, string y, int p) : Ship(n, y) {

        passengers = p;

    }


    virtual void print() {//Display output

        cout << "\nShip's Name: " << getName()

             << "\nMaximum number passengers:" << passengers << endl;

    }

};


class CargoShip : public Ship {


private:
    int tonnage;

public:


    CargoShip(string n, string y, int t) : Ship(n, y) {

        tonnage = t;

    }


    virtual void print() {


        cout << "\nShip's Name:" << getName() << "\nCapacity:" << tonnage << " tonnage" << endl;

    }

};


int main() {


    int i;
    Ship *ships[3] = {new Ship(" Ashley", "2011"),

                      new CruiseShip(" Richard", "2012", 2000),

                      new CargoShip(" Mariella", "2013", 5000)

    };


    for (i = 0; i < 3; i++) {

        ships[i]->print();
    }

    return 0;

}

