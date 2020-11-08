#include <iostream>
#include "PersonalBudget.h"
#include "AuxiliaryMethods.h"

using namespace std;

char chooseOptionsFromMainMenu();
char chooseOptionFromUsersMenu();

int main() {
    PersonalBudget personalBudget("users.xml", "incomes.xml", "expenses.xml");
    //userManager.registerUser();
    //personalBudget.registerUser();
    personalBudget.wypiszWszystkichUzytkownikow();
    system("pause");
    //personalBudget.loginUser();
    //personalBudget.changePassword();
    //personalBudget.addIncome();

    char choice;
    while(true) {
        if (!personalBudget.isUserLoggedIn()) {
            choice = chooseOptionsFromMainMenu();

            switch (choice) {
            case '1':
                personalBudget.registerUser();
                break;
            case '2':
                personalBudget.loginUser();
                break;
            case '9':
                exit(0);
            default:
                cout << endl << "No such option in menu." << endl << endl;
                system("pause");
                break;
            }
        } else {
            choice = chooseOptionFromUsersMenu();
             switch (choice) {
           case '1':
             personalBudget.addIncome();
              break;
            case '2':
                personalBudget.addExpense();
                break;
            case '3':
                personalBudget.displayBalanceSheetFromCurrentMonth();
                break;
            case '4':
                personalBudget.displayBalanceSheetFromPreviousMonth();
                break;
          //  case '5':
          //      personalBudget.showBalanceFromPeriod();
           //     break;
            case '6':
                personalBudget.changePassword();
                break;
            case '7':
                personalBudget.logoutUser();
                break;
            }
        }



    }
    return 0;
}

char chooseOptionsFromMainMenu() {
    char choice;

    system("cls");
    cout << "    >>> MAIN  MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Register" << endl;
    cout << "2. Log in" << endl;
    cout << "9. Exit" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = AuxiliaryMethods :: loadChar();

    return choice;
}

char chooseOptionFromUsersMenu() {
    char choice;

    system("cls");
    cout << "             >>> USER'S MENU <<<" << endl;
    cout << "--------------------------------------------" << endl;
    cout << "1. Add income" << endl;
    cout << "2. Add expense" << endl;
    cout << "3. Show balance from current month" << endl;
    cout << "4. Show balance from previous month" << endl;
    cout << "5. Show balance from selected period of time" << endl;
    cout << "--------------------------------------------" << endl;
    cout << "6. Change password" << endl;
    cout << "7. Log out" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = AuxiliaryMethods :: loadChar();

    return choice;
}
