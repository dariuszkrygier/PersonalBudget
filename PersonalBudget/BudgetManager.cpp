#include "BudgetManager.h"

void BudgetManager :: addIncome() {
    Income income;
    system("cls");
    char choice;
    string date;
    choice = chooseTypeOfDateFromMenu();
    date = setTheDateOfTheFinancialOperation(choice);
    if (date == "0") {
        cout << "The date is incorrect." << endl;
        system("pause");
        return;
    } else {
        income = addDetailsOfTheIncome(date);
        incomes.push_back(income);
        incomesFile.saveIncomeToFile(income);
        cout << "Income has been added." << endl;
        system("pause");
    }
}

void BudgetManager :: addExpense() {
    Expense expense;
    system("cls");
    char choice;
    string date;
    choice = chooseTypeOfDateFromMenu();
    date = setTheDateOfTheFinancialOperation(choice);
    if (date == "0") {
        cout << "The date is incorrect." << endl;
        system("pause");
        return;
    } else {
        expense = addDetailsOfTheExpense(date);
        expenses.push_back(expense);
        expensesFile.saveExpenseToFile(expense);
        cout << "Expense has been added." << endl;
        system("pause");
    }
}

char BudgetManager :: chooseTypeOfDateFromMenu() {

    char choice;

    cout << ">>>> DATE SELECTION <<<<" << endl;
    cout << "--------------------------" << endl;
    cout << "Select date:" << endl;
    cout << "1. Add operation with current date." << endl;
    cout << "2. Set date of the operation." << endl;
    choice = AuxiliaryMethods :: loadChar();

    return choice;
}

Income BudgetManager :: addDetailsOfTheIncome(string dateOfTheIncome) {
    Income income;
    string nameOfTheIncome;
    string amountOfIncome;

    income.setIncomeId(incomesFile.getTheLastIncomeId() + 1);

    income.setUserId(LOGGED_IN_USER_ID);

    income.setDate(dateOfTheIncome);

    cout << "Enter name of the income: ";
    nameOfTheIncome = AuxiliaryMethods :: loadLine();
    income.setItem(nameOfTheIncome);

    cout << "Enter amount: ";
    cin >> amountOfIncome;
    double amountOfIncomeAsDouble = checkFormatAndChangeIntoDouble(amountOfIncome);
    income.setAmount(amountOfIncomeAsDouble);

    return income;
}

Expense BudgetManager :: addDetailsOfTheExpense(string dateOfTheExpense) {
    Expense expense;
    string nameOfTheExpense;
    string amountOfExpense;

    expense.setExpenseId(expensesFile.getTheLastExpenseId() + 1);

    expense.setUserId(LOGGED_IN_USER_ID);

    expense.setDate(dateOfTheExpense);

    cout << "Enter name of the expense: ";
    nameOfTheExpense = AuxiliaryMethods :: loadLine();
    expense.setItem(nameOfTheExpense);

    cout << "Enter amount: ";
    cin >> amountOfExpense;
    double amountOfExpenseAsDouble = checkFormatAndChangeIntoDouble(amountOfExpense);
    expense.setAmount(amountOfExpenseAsDouble);

    return expense;
}

double BudgetManager :: checkFormatAndChangeIntoDouble (string amount) {
    size_t i = amount.find(",");
    if (i != string::npos)
        amount.replace(i,1,".");
    stringstream ss;
    double amountAsADouble;
    ss << amount;
    ss >> amountAsADouble;

    return amountAsADouble;
}

string BudgetManager :: setTheDateOfTheFinancialOperation (char choice) {
    string date;
    switch (choice) {
    case '1':
        date = AuxiliaryMethods :: setCurrentDateOfTheOperation();
        return date;
        break;
    case '2':
        date = AuxiliaryMethods :: setUsersDateOfTheOperation();
        return date;
        break;
    }
}
