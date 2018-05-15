//
// Created by Richard Houth on 5/13/18.
//

#ifndef BANKACCOUNT_BANKACCOUNT_H
#define BANKACCOUNT_BANKACCOUNT_H


class BankAccount {

protected:

    double balance;

    int noOfDeposit;

    int noOfWithdrawl;

    double AnnualInterestRate;

    double monthlyServiceCharge;

public:

    BankAccount(double bal, double interestRate) {

        balance = bal;

        AnnualInterestRate = interestRate;

        noOfDeposit = 0;

        noOfWithdrawl = 0;

        monthlyServiceCharge = 0;

    }

    virtual void deposit(double amount) {

        balance += amount;

        noOfDeposit++;

    }

    virtual void withdraw(double amount) {

        balance -= amount;

        noOfWithdrawl++;

    }

    virtual void calcint() {

        double MonthlyInterestRate = (AnnualInterestRate / 12);

        double MonthlyInterest = balance * MonthlyInterestRate;

        balance = balance + MonthlyInterest;

    }

    virtual void monthlyProc() {

        balance -= monthlyServiceCharge;

        calcint();

        noOfDeposit = 0;

        noOfWithdrawl = 0;

        monthlyServiceCharge = 0;

    }

    double getbalance() {

        return balance;

    }

    int getDeposit() {

        return noOfDeposit;

    }

    int getWithdrawal() {

        return noOfWithdrawl;

    }

    double getMonthlyServiceCharge() {

        return monthlyServiceCharge;

    }

};

#endif //BANKACCOUNT_BANKACCOUNT_H
