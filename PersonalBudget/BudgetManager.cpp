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

void BudgetManager :: displayBalanceSheetFromCurrentMonth() {
    setprecision (2);
    vector <Income> incomesFromCurrentMonth;
    vector <Income> sortedIncomesFromCurrentMonth;
    system("cls");
    incomesFromCurrentMonth = loadIncomesFromCurrentMonth();
    sortedIncomesFromCurrentMonth = sortIncomesFromChosenTimePeriod(incomesFromCurrentMonth);
    displayIncomesFromChosenTimePeriod(sortedIncomesFromCurrentMonth);
    double totalIncomes;
    totalIncomes = sumIncomes(incomesFromCurrentMonth);
    cout << "---------------------------------------" << endl;
    cout << "TOTAL INCOMES: " << totalIncomes << endl;
    vector <Expense> expensesFromCurrentMonth;
    vector <Expense> sortedExpensesFromCurrentMonth;
    expensesFromCurrentMonth = loadExpensesFromCurrentMonth();
    sortedExpensesFromCurrentMonth = sortExpensesFromChosenTimePeriod(expensesFromCurrentMonth);
    displayExpensesFromChosenTimePeriod(sortedExpensesFromCurrentMonth);
    double totalExpenses;
    totalExpenses = sumExpenses(expensesFromCurrentMonth);
    cout << "---------------------------------------" << endl;
    cout << "TOTAL EXPENSES: " << totalExpenses << endl << endl;
    double balanceFromCurrentMonth = sumIncomesAndExpenses(totalIncomes, totalExpenses);
    cout << "---------------------------------------" << endl;
    cout << "BALANCE FROM CURRENT MONTH: " << balanceFromCurrentMonth << endl;
    cout << "---------------------------------------" << endl;
    system("pause");
}

vector <Income> BudgetManager :: loadIncomesFromCurrentMonth() {
    Income income;
    vector <Income> incomesFromCurrentMonth;
    int currentYear = AuxiliaryMethods :: getCurrentYear();
    int currentMonth = AuxiliaryMethods :: getCurrentMonth();
    vector <Income>::iterator itr = incomes.begin();
    while (itr != incomes.end()) {
        string date = itr -> getDate();
        int yearFromUsersDate = AuxiliaryMethods :: getYearFromOperationDate(date);
        int monthFromUsersDate = AuxiliaryMethods :: getMonthFromOperationDate(date);
        if (yearFromUsersDate == currentYear && monthFromUsersDate == currentMonth) {
            income.setIncomeId(itr -> getIncomeId());
            income.setUserId(itr -> getUserId());
            income.setDate(itr -> getDate());
            income.setItem(itr -> getItem());
            income.setAmount(itr -> getAmount());
            incomesFromCurrentMonth.push_back(income);
        }
        itr++;
    }
    return incomesFromCurrentMonth;
}
vector <Expense> BudgetManager :: loadExpensesFromCurrentMonth() {
    Expense expense;
    vector <Expense> expensesFromCurrentMonth;
    int currentYear = AuxiliaryMethods :: getCurrentYear();
    int currentMonth = AuxiliaryMethods :: getCurrentMonth();
    vector <Expense>::iterator itr = expenses.begin();
    while (itr != expenses.end()) {
        string date = itr -> getDate();
        int yearFromUsersDate = AuxiliaryMethods :: getYearFromOperationDate(date);
        int monthFromUsersDate = AuxiliaryMethods :: getMonthFromOperationDate(date);
        if (yearFromUsersDate == currentYear && monthFromUsersDate == currentMonth) {
            expense.setExpenseId(itr -> getExpenseId());
            expense.setUserId(itr -> getUserId());
            expense.setDate(itr -> getDate());
            expense.setItem(itr -> getItem());
            expense.setAmount(itr -> getAmount());
            expensesFromCurrentMonth.push_back(expense);
        }
        itr++;
    }
    return expensesFromCurrentMonth;
}

vector <Income> BudgetManager :: sortIncomesFromChosenTimePeriod(vector <Income> incomes) {
    sort(incomes.begin(),incomes.end());
    return incomes;
}

vector <Expense> BudgetManager :: sortExpensesFromChosenTimePeriod(vector <Expense> expenses) {
    sort(expenses.begin(),expenses.end());
    return expenses;
}

void BudgetManager :: displayIncomesFromChosenTimePeriod(vector <Income> incomes) {
    cout << "----------INCOMES----------" << endl;
    for(int i = 0; i < incomes.size(); i++) {
        cout<<incomes.at(i).getDate()<<" "<<incomes.at(i).getItem()<< " " <<incomes.at(i).getAmount()<< endl;
    }
}

void BudgetManager :: displayExpensesFromChosenTimePeriod(vector <Expense> expenses) {
    cout << endl << "---------EXPENSES----------" << endl;
    for(int i = 0; i < expenses.size(); i++) {
        cout<<expenses.at(i).getDate()<<" "<<expenses.at(i).getItem()<< " " <<expenses.at(i).getAmount()<< endl;
    }
}

double BudgetManager :: sumIncomes (vector <Income> incomes) {
    double totalIncomes = 0;
    for(int i = 0; i < incomes.size(); i++) {
        totalIncomes += incomes.at(i).getAmount();
    }
    return totalIncomes;
}

double BudgetManager :: sumExpenses (vector <Expense> expenses) {
    double totalExpenses = 0;
    for(int i = 0; i < expenses.size(); i++) {
        totalExpenses += expenses.at(i).getAmount();
    }
    return totalExpenses;
}

double BudgetManager :: sumIncomesAndExpenses (double incomes, double expenses) {
    double balance = incomes - expenses;
    return balance;
}

bool operator < ( const Income &i1, const Income &i2) {
    return AuxiliaryMethods :: convertStringToInt (AuxiliaryMethods :: removeChosenCharacterFromString (i1.getConstDate()))
    < AuxiliaryMethods :: convertStringToInt (AuxiliaryMethods :: removeChosenCharacterFromString (i2.getConstDate()));
}

bool operator < ( const Expense &e1, const Expense &e2) {
    return AuxiliaryMethods :: convertStringToInt (AuxiliaryMethods :: removeChosenCharacterFromString (e1.getConstDate()))
    < AuxiliaryMethods :: convertStringToInt (AuxiliaryMethods :: removeChosenCharacterFromString (e2.getConstDate()));
}

