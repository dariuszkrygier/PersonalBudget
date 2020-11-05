#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H
#include <iostream>
#include <algorithm>
#include <iomanip>
#include "Income.h"
#include "Expense.h"
#include "IncomesFile.h"
#include "AuxiliaryMethods.h"
#include <vector>

using namespace std;

class BudgetManager {
    const int LOGGED_IN_USER_ID;
    vector <Income> incomes;
    IncomesFile incomesFile;
    //vector <Expense> expenses;
    AuxiliaryMethods auxiliaryMethods;
    char chooseTypeOfDateFromMenu();
    string setTheDateOfTheFinancialOperation (char choice);
    Income addDetailsOfTheIncome(string dateOfTheExpense);
    double checkFormatAndChangeIntoDouble (string amount);

public:
    BudgetManager (string incomesFileName, int loggedInUserId) : incomesFile (incomesFileName), LOGGED_IN_USER_ID(loggedInUserId) {
        incomes = incomesFile.loadIncomesOfLoggedInUserFromFile(LOGGED_IN_USER_ID);
    };
    void addIncome();
    void addExpense();
    void displayBalanceSheetFromCurrentMonth();
    void displayBalanceSheetFromPreviousMonth();
    void displayBalanceSheetFromChosenTimePeriod();

};

#endif
