#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H
#include <iostream>
#include <algorithm>
#include <iomanip>
#include "Income.h"
#include "Expense.h"
#include "AuxiliaryMethods.h"
#include <vector>

using namespace std;

class BudgetManager {
    const int LOGGED_IN_USER_ID;
    vector <Income> incomes;
    //vector <Expense> expenses;
    AuxiliaryMethods auxiliaryMethods;
    char chooseTypeOfDateFromMenu();
    string setTheDateOfTheFinancialOperation (char choice);
    Income addDetailsOfTheIncome(string dateOfTheExpense);
    double checkFormatAndChangeIntoDouble (string amount);

public:
    BudgetManager (int loggedInUserId) : LOGGED_IN_USER_ID(loggedInUserId) {
    };
    void addIncome();
    void addExpense();
    void displayBalanceSheetFromCurrentMonth();
    void displayBalanceSheetFromPreviousMonth();
    void displayBalanceSheetFromChosenTimePeriod();

};

#endif
