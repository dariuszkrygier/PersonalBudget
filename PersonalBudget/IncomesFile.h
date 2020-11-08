#ifndef INCOMESFILE_H
#define INCOMESFILE_H
#include <iostream>
#include <vector>
#include <sstream>
#include "Income.h"
#include "Markup.h"
#include "AuxiliaryMethods.h"

using namespace std;

class IncomesFile {
    Income income;
    vector<Income> incomes;
    const string INCOMES_FILE_NAME;
    int lastIncomeId;

public:
    IncomesFile(string incomesFileName);
    vector <Income> loadIncomesOfLoggedInUserFromFile(int loggedInUserId);
    int getTheLastIncomeId();
    void saveIncomeToFile(Income income);
};

#endif
