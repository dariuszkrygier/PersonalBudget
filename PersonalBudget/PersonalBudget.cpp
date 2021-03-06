#include "PersonalBudget.h"

void PersonalBudget :: registerUser() {
    userManager.registerUser();
}
void PersonalBudget :: loginUser() {
    userManager.loginUser();
    if (userManager.isUserLoggedIn()) {
        budgetManager = new BudgetManager (INCOMES_FILE_NAME, EXPENSES_FILE_NAME, userManager.getLoggedinUserId());
    }
}
void PersonalBudget :: changePassword() {
    userManager.changePassword();
}
void PersonalBudget :: logoutUser() {
    userManager.logoutUser();
    delete budgetManager;
    budgetManager = NULL;
}
void PersonalBudget :: wypiszWszystkichUzytkownikow() {
    userManager.wypiszWszystkichUzytkownikow();
}
bool PersonalBudget :: isUserLoggedIn() {
    return userManager.isUserLoggedIn();
}
void PersonalBudget :: addIncome() {
    budgetManager -> addIncome();
}
void PersonalBudget :: addExpense() {
    budgetManager -> addExpense();
}
void PersonalBudget :: displayBalanceSheetFromCurrentMonth() {
    budgetManager -> displayBalanceSheetFromCurrentMonth();
}
void PersonalBudget :: displayBalanceSheetFromPreviousMonth() {
    budgetManager -> displayBalanceSheetFromPreviousMonth();
}
void PersonalBudget :: displayBalanceSheetFromChosenTimePeriod() {
    budgetManager -> displayBalanceSheetFromChosenTimePeriod();
}
