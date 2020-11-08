#ifndef EXPENSESFILE_H
#define EXPENSESFILE_H
#include <iostream>
#include <vector>
#include <sstream>
#include "Expense.h"
#include "Markup.h"
#include "AuxiliaryMethods.h"

using namespace std;

class ExpensesFile {
    Expense expense;
    vector<Expense> expenses;
    const string EXPENSES_FILE_NAME;
    int lastExpenseId;

public:
    ExpensesFile(string expensesFileName);
    vector <Expense> loadExpensesOfLoggedInUserFromFile(int loggedInUserId);
    int getTheLastExpenseId();
    void saveExpenseToFile(Expense expense);
};

#endif
