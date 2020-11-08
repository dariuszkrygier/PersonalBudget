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
    vector <Income> loadIncomesFromCurrentMonth();
    vector <Income> loadIncomesFromPreviousMonth();
    vector <Income> loadIncomesFromChosenTimePeriod(string startDate, string endDate);
    vector <Expense> loadExpensesFromCurrentMonth();
    vector <Expense> loadExpensesFromPreviousMonth();
    vector <Expense> loadExpensesFromChosenTimePeriod(string startDate, string endDate);
    vector <Income> sortIncomesFromChosenTimePeriod(vector <Income> incomes);
    vector <Expense> sortExpensesFromChosenTimePeriod(vector <Expense> expenses);
    void displayIncomesFromChosenTimePeriod(vector <Income> incomes);
    void displayExpensesFromChosenTimePeriod(vector <Expense> expenses);
    double sumIncomes (vector <Income> incomes);
    double sumExpenses (vector <Expense> expenses);
    double sumIncomesAndExpenses (double incomes, double expenses);


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
