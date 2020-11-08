#ifndef INCOME_H
#define INCOME_H
#include <iostream>

using namespace std;

class Income {
    int incomeId;
    int userId;
    string date;
    string item;
    double amount;


public:
    void setIncomeId (int newIncomeId);
    void setUserId (int newUserId);
    void setDate (string newDate);
    void setItem (string newItem);
    void setAmount (double newAmount);


    int getIncomeId();
    int getUserId();
    string getDate();
    string getItem();
    double getAmount();
    string getConstDate() const;

};


bool operator<(const Income &i1, const Income &i2);

#endif
