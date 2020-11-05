#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include "UserManager.h"
#include "BudgetManager.h"


using namespace std;

class PersonalBudget {
    UserManager userManager;
    BudgetManager *budgetManager;
    const string INCOMES_FILE_NAME;
    const string EXPENSES_FILE_NAME;


public:
    PersonalBudget(string usersFileName, string incomesFileName, string expensesFileName) : userManager (usersFileName),
        INCOMES_FILE_NAME (incomesFileName), EXPENSES_FILE_NAME (expensesFileName) {
        budgetManager = NULL;
    };

    ~PersonalBudget() {
        delete budgetManager;
        budgetManager = NULL;
    }
    void registerUser();
    void loginUser();
    void changePassword();
    void logoutUser();
    void wypiszWszystkichUzytkownikow();
    bool isUserLoggedIn();
    void addIncome();
    void addExpense();
};
