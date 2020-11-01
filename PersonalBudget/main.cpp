#include <iostream>
#include "PersonalBudget.h"
#include "AuxiliaryMethods.h"

using namespace std;

char chooseOptionsFromMainMenu();

int main() {
    PersonalBudget personalBudget("users.xml");
    //userManager.registerUser();
    //personalBudget.registerUser();
    //personalBudget.wypiszWszystkichUzytkownikow();
    //personalBudget.loginUser();
    //personalBudget.changePassword();
    //personalBudget.logoutUser();

 char choice;
   while(true)
   {
        if (!personalBudget.isUserLoggedIn())
        {
            choice = chooseOptionsFromMainMenu();

            switch (choice)
            {
            case '1':
                personalBudget.registerUser();
                break;
            case '2':
                personalBudget.loginUser();
                break;
            case '9':
                exit(0);
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else {
                }



}
return 0;
}

char chooseOptionsFromMainMenu()
{
    char choice;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = AuxiliaryMethods :: loadChar();

    return choice;
}

