#include "UserManager.h"
#include "AuxiliaryMethods.h"

void UserManager :: registerUser() {
    User user = specifyNewUserData();

    users.push_back(user);
    //UsersFile usersFile;

    usersFile.saveUserToFile(user);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

User UserManager :: specifyNewUserData() {
    User user;

    user.setId(getNewUserId());

    string name;
    cout << "Podaj imie: ";
    cin >> name;
    user.setName (name);

    string surname;
    cout << "Podaj nazwisko: ";
    cin >> surname;
    user.setSurname (surname);

    string login;

    do {
        cout << "Podaj login: ";
        cin >> login;
        user.setLogin(login);
    } while (loginExists(user.getLogin()) == true);

    string password;
    cout << "Podaj haslo: ";
    cin >> password;
    user.setPassword (password);

    return user;
}

int UserManager :: getNewUserId() {
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId () + 1;
}

bool UserManager :: loginExists (string login) {
    for (int i = 0; i < users.size(); i++) {
        if (users[i].getLogin() == login) {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }

    }
    return false;

}

void UserManager :: wypiszWszystkichUzytkownikow() {
    for (int i = 0; i < users.size(); i++) {
        cout << users[i].getId() << endl;
        cout << users[i].getName() << endl;
        cout << users[i].getSurname() << endl;
        cout << users[i].getLogin() << endl;
        cout << users[i].getPassword() << endl;
    }
}

int UserManager :: loginUser() {
    User user;
    string login = "", password = "";

    cout << endl << "Podaj login: ";
    login = AuxiliaryMethods :: loadLine();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end()) {
        if (itr -> getLogin() == login) {
            for (int numberOfAttempts = 3; numberOfAttempts > 0; numberOfAttempts--) {
                cout << "Podaj haslo. Pozostalo prob: " << numberOfAttempts << ": ";
                password = AuxiliaryMethods :: loadLine();

                if (itr -> getPassword() == password) {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    loggedUserId = itr -> getId();
                    return loggedUserId;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return 0;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return 0;
}

void UserManager :: changePassword() {
    string newPassword = "";
    cout << "Podaj nowe haslo: ";
    newPassword = AuxiliaryMethods :: loadLine();

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++) {
        if (itr -> getId() == loggedUserId) {
            itr -> setPassword(newPassword);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    //plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(users);
}

void UserManager :: logoutUser() {
    if (loggedUserId==0)
        cout<<"Nikt nie jest zalogowany"<<endl;
    else {
        vector <User>::iterator itr = users.begin();
        while (itr != users.end()) {
            if (itr -> getId() == loggedUserId)
                break;
            itr++;
        }
        cout<<"Uzytkownik: "<<itr->getLogin()<<", wylogowany."<<endl;
        loggedUserId=0;
    }
}

int UserManager :: getLoggedinUserId() {
    return loggedUserId;
}

bool UserManager :: isUserLoggedIn() {
    if (loggedUserId>0)
        return true;
    else {
        return false;
    }
}
