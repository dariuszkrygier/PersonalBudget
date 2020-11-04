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


public:
    PersonalBudget(string usersFileName) : userManager (usersFileName) {

    };

    ~PersonalBudget() {
        delete budgetManager;
    }
    void registerUser();
    void loginUser();
    void changePassword();
    void logoutUser();
    void wypiszWszystkichUzytkownikow();
    bool isUserLoggedIn();
    void addIncome();
};
