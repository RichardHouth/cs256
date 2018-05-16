#include <iostream>
#include <vector>
#include <string>
using namespace std;

class  Human{
private:
     string name;
     int age;
     char sex;
     string work;
    Human(){
        name = "";
        age = 0;
    }

protected:

     Human(string n, int a, char s){
        name = n;
        age = a;
        sex = s;
    }
    friend class Parent;
    friend class Child;

public:
   // virtual work();

    void setWork(string w){
       work =w;
   }
    void setName(string nm){
        name = nm;
    }

    void setAge(int ag){
        age = ag;
    }

    void setSex(char se){
        sex = se;
    }
    string getName(){
        return name;
    }

    int getAge(){
        return age;
    }

    char getSex(){
        return sex;
    }


};

class Parent: public Human{
private:
    vector<Child> children;

public:

    void setAge(int a){
        age = a;
    }
    void setName(string n){
        name = n;
    }
    void setSex(char s){
        sex = s;
    }
    int getChildAge(){
        return age;
    }
    string getChildName(){
        return name;
    }
    char getChildSex(){
        return sex;
    }

};

class Child: public Human{
private:
    Parent Mom;
    Parent Dad;
    Child(){
        Mom;
        Dad;
    }

public:
    Child(string nm, int ag){
        name = nm;
        age = ag;
    }

};


int main() {

    Human Homer("Homer", 36, 'M');
    Human Marge("Marge", 34, 'F');
    Human Lisa("Lisa", 12, 'F');
    Human Bart("Bart", 10, 'M');
    Human Maggie("Maggie", 3, 'F');

    Marge.setName("maggie");
    Homer.setName("Bart");
    Homer.setName("Lisa");

    cout << "Homer " << endl;
    cout << "Age: " << Homer.getAge();
    cout << "Sex: " << Homer.getSex();
    cout << "Work: " << Homer.getWork();




    return 0;
}