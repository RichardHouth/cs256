//Richard Houth
//CS 256
#pragma once
#include <string>
#include <vector>
using namespace std;



class finalExam {
private:

	vector <int> num;
public:

	finalExam();
	finalExam(string n);
	string ToString(finalExam other);
	finalExam operator +(const finalExam &k) const;
	finalExam operator -(const finalExam &k) const;
	finalExam operator *(const finalExam &k) const;
	finalExam operator /(const finalExam &k) const;
	finalExam operator %(const finalExam &k) const;
	~finalExam();
};
