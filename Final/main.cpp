
#include "finalExam.h"
using namespace std;
#include <string>
#include <vector>
#include <algorithm>


//default constructor
finalExam::finalExam(){

}

finalExam operator +(finalExam &k){
    finalExam output;
    int c = 0, sizeNumTwo = this->num.size(), sizeNumOne = k.num.size(), difference = sizeNumTwo - sizeNumOne;
    for (int i = sizeNumOne - 1; i >= 0; i--) {
        int sum = this->num.at(i + difference) + k.num.at(i) + c;
        output.num.push_back(sum % 10);
        c = sum / 10;
    }
    for (int i = sizeNumTwo - sizeNumOne - 1; i >= 0; i--) {
        int sum = this->num.at(i) + c;
        output.num.push_back(sum % 10);
        c = sum / 10;
    }
    // remaining carry
    if (c)
        output.num.push_back(c);
    reverse(output.num.begin(), output.num.end());
    return output;
}

finalExam finalExam::operator -(const finalExam &k) const{
    finalExam output;
    int c = 0, difference = this->num.size() - k.num.size(), sizeNumOne = this->num.size(), sizeNumTwo = k.num.size();
    int s = 0;
    reverse(this->num.begin(), this->num.end());
    reverse(k.num.begin(), k.num.end());
    for (int i = 0; i < sizeNumTwo; i++) {
        s = this->num.at(i) - (k.num.at(i) - c);
        if (s < 0) {
            s += 10;
            c = 1;
        }
        else
            c = 0;
        output.num.push_back(s);
    }
    for (int i = sizeNumTwo; i < sizeNumOne; i++) {
        s = this->num.at(i) - c;
        if (s < 0) {
            s += 10;
            c = 1;
        }
        else
            c = 0;
        output.num.push_back(s);
    }
    reverse(output.num.begin(), output.num.end());
    return output;
}

finalExam finalExam::operator *(const finalExam &k) const{
    finalExam output;
    int c, sum = 0, sizeNumOne = this->num.size(), sizeNumTwo = k.num.size(), indexOne = 0, indexTwo = 0, valueOne, valueTwo;
    if ((sizeNumOne == 1 && this->num.at(0) == 0) || (sizeNumTwo == 1 && k.num.at(0) == 0)) {
        output.num.push_back(0);
        return output;
    }
    vector<int> scaledVec(sizeNumOne + sizeNumTwo, 0);
    output.num = scaledVec;
    for (int i = sizeNumOne - 1; i >= 0; i--) {
        c = 0;
        valueOne = this->num.at(i);
        indexTwo = 0;
        for (int j = sizeNumTwo - 1; j >= 0; j--) {
            valueTwo = k.num.at(j);

            sum = valueOne * valueTwo + output.num.at(indexOne + indexTwo) + c;
            // carry for next iterations
            c = sum / 10;
            output.num.at(indexOne + indexTwo) = sum % 10;
            indexTwo++;
        }
        if (c > 0)
            output.num.at(indexOne + indexTwo) += c;
        //shift
        indexOne++;
    }
    // ignore 0
    int i = output.num.size() - 1;
    while (i >= 0 && output.num.at(i) == 0)
        i--;
    reverse(output.num.begin(), output.num.end());
    return output;
}

finalExam finalExam::operator %(const finalExam &k) const {
    finalExam output;
    finalExam f;
    f.num = this->num;
    int remain = 0;
    while (true) {
        output = f - k;
        remain++;
        if (this->num.size() > k.num.size())
            return remain;
        k.num = output.num;
        return output;
    }
}

finalExam finalExam::operator /(const finalExam &k) const{
    finalExam output;
    finalExam begin;
    begin.num = this->num;
    int quotient = 0;
    while (true) {
        output = begin - k;
        if (this->num.size() < k.num.size())
            return quotient;
        quotient++;
        begin.num = output.num;
    }
    return output;
}

//destructor
finalExam::~finalExam(){

}