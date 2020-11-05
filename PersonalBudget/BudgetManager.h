#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H
#include <iostream>
#include <algorithm>
#include <iomanip>
#include "Income.h"
#include "Expense.h"
#include "IncomesFile.h"
#include "ExpensesFile.h"
#include "AuxiliaryMethods.h"
#include <vector>

using namespace std;

class BudgetManager {
    const int LOGGED_IN_USER_ID;
    vector <Income> incomes;
    IncomesFile incomesFile;
    vector <Expense> expenses;
    ExpensesFile expensesFile;
    AuxiliaryMethods auxiliaryMethods;
    char chooseTypeOfDateFromMenu();
    string setTheDateOfTheFinancialOperation (char choice);
    Income addDetailsOfTheIncome(string dateOfTheIcome);
    Expense addDetailsOfTheExpense(string dateOfTheExpense);
    double checkFormatAndChangeIntoDouble (string amount);


public:
    BudgetManager (string incomesFileName, string expensesFileName, int loggedInUserId) :
        incomesFile (incomesFileName), expensesFile(expensesFileName), LOGGED_IN_USER_ID(loggedInUserId) {
        incomes = incomesFile.loadIncomesOfLoggedInUserFromFile(LOGGED_IN_USER_ID);
        expenses = expensesFile.loadExpensesOfLoggedInUserFromFile(LOGGED_IN_USER_ID);
    };
    void addIncome();
    void addExpense();
    void displayBalanceSheetFromCurrentMonth();
    void displayBalanceSheetFromPreviousMonth();
    void displayBalanceSheetFromChosenTimePeriod();

};

#endif
