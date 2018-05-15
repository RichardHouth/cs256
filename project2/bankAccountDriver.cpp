//Richard Houth
//CS 256

#include <iostream>
#include<stdbool.h>
#include "bankAccount.h"

using namespace std;

class SavingAccount : public BankAccount {

private:

    bool status;

public:

    SavingAccount(double balance, double rate) : BankAccount(balance, rate) {

    }

    bool checkStatus() {

        if (BankAccount::balance < 25.0)

            return false;

        else

            return true;

    }

    void withdraw(double amount) {

        if (checkStatus()) {

            BankAccount::withdraw(amount);

        }

    }

    void deposit(double amount) {

        if (checkStatus() == false) {

            if (BankAccount::balance + amount > 25)

                status = true;

        }

        BankAccount::deposit(amount);

    }

    void monthlyProc() {

        if (BankAccount::noOfWithdrawl > 4) {

            BankAccount::monthlyServiceCharge += 1;

            BankAccount::balance -= 1;

            if (BankAccount::balance < 25)

                status = false;

        }


    }

};

class CheckingAccount : public BankAccount {

public:

    CheckingAccount(double balance, double rate) : BankAccount(balance, rate) {

    }

    void withdraw(double amount) {

        if (balance - amount < 0) {

            monthlyServiceCharge += 15;

            balance -= 15;

        } else

            BankAccount::withdraw(amount);

    }

    void monthlyProc() {

        monthlyServiceCharge += 5;

        monthlyServiceCharge += 0.10 * noOfWithdrawl;


    }

};

int main() {

    BankAccount *saving = new SavingAccount(100, 15);

    cout << "please enter amount to deposit in saving account: ";

    double depositAmount, withdrawAmount;

    cin >> depositAmount;

    saving->deposit(depositAmount);

    double monthStartBalance = depositAmount;

    cout << "please enter amount to withdraw from saving account: ";

    cin >> withdrawAmount;

    saving->withdraw(withdrawAmount);

    cout << "Month starting balance: " << monthStartBalance << endl;

    cout << "Total number of deposit: " << saving->getDeposit() << endl;

    cout << "Total number of withdrawal: " << saving->getWithdrawal() << endl;

    cout << "Monthly service charge: " << saving->getMonthlyServiceCharge() << endl;

    cout << "Month ending balance: " << saving->getbalance() << endl;


    BankAccount *checking = new CheckingAccount(500, 10);

    cout << "Enter amount to deposit in checking account: ";


    cin >> depositAmount;

    checking->deposit(depositAmount);

    monthStartBalance = depositAmount;

    cout << "Enter amount to withdraw from checking account: ";

    cin >> withdrawAmount;

    checking->withdraw(withdrawAmount);

    cout << "Month starting balance: " << monthStartBalance << endl;

    cout << "Total number of deposit: " << checking->getDeposit() << endl;

    cout << "Total number of withdrawal: " << checking->getWithdrawal() << endl;

    cout << "Monthly service charge: " << checking->getMonthlyServiceCharge() << endl;

    cout << "Month Ending balance: " << checking->getbalance() << endl;

    getchar();

    return 0;

}