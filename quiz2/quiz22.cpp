#include <iostream>
#include <string>
using namespace std;
//Richard Houth
//CS 256 QUIZ 2

class Circle {
private:
    double radius;
    double pi = 3.14159;

public:

    Circle(){
        radius = 0.0;
    }

    Circle(double r){
        radius = r;
    }

    void setRadius(double r){
        radius = r;
    }


    double getRadius(){
        return radius;
    }

    double getArea(){

        return pi * getRadius() * getRadius();
    }

    double getDiameter(){
        return 2*getRadius();
    }

    double getCircumference(){
        return 2 * pi * getRadius();
    }

};

int main(int argc, char *argv[]) {

    double user;
    cout << "Please enter the radius: " << endl;
    cin >> user;

    Circle circle;
    circle.setRadius(user);
    cout << "Circumference is: " << circle.getCircumference() << endl;
    cout << "Area is : " << circle.getArea() << endl;
    cout << "diameter is : " << circle.getDiameter() << endl;


    return 0;
}
