#include "UserManager.h"
#include "AuxiliaryMethods.h"

void UserManager :: registerUser() {
    User user = specifyNewUserData();

    users.push_back(user);
    //UsersFile usersFile;

    usersFile.saveUserToFile(user);

    cout << endl << "Success" << endl << endl;
    system("pause");
}

User UserManager :: specifyNewUserData() {
    User user;

    user.setId(getNewUserId());

    string name;
    cout << "Enter name: ";
    cin >> name;
    user.setName (name);

    string surname;
    cout << "Enter surname: ";
    cin >> surname;
    user.setSurname (surname);

    string login;

    do {
        cout << "Enter login: ";
        cin >> login;
        user.setLogin(login);
    } while (loginExists(user.getLogin()) == true);

    string password;
    cout << "Enter password: ";
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
            cout << endl << "User with this login already exsists." << endl;
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

    cout << endl << "Enter login: ";
    login = AuxiliaryMethods :: loadLine();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end()) {
        if (itr -> getLogin() == login) {
            for (int numberOfAttempts = 3; numberOfAttempts > 0; numberOfAttempts--) {
                cout << "Enter password. Attemps remaining: " << numberOfAttempts << ": ";
                password = AuxiliaryMethods :: loadLine();

                if (itr -> getPassword() == password) {
                    cout << endl << "You are logged." << endl << endl;
                    system("pause");
                    loggedUserId = itr -> getId();
                    return loggedUserId;
                }
            }
            cout << "You entered wrong password 3 times." << endl;
            system("pause");
            return 0;
        }
        itr++;
    }
    cout << "No user with this login" << endl << endl;
    system("pause");
    return 0;
}

void UserManager :: changePassword() {
    string newPassword = "";
    cout << "Enter new password: ";
    newPassword = AuxiliaryMethods :: loadLine();

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++) {
        if (itr -> getId() == loggedUserId) {
            itr -> setPassword(newPassword);
            cout << "Password changed." << endl << endl;
            system("pause");
        }
    }
    usersFile.saveAllUsersToFile(users);
}

void UserManager :: logoutUser() {
    if (loggedUserId==0)
        cout<<"Nobody is logged in"<<endl;
    else {
        vector <User>::iterator itr = users.begin();
        while (itr != users.end()) {
            if (itr -> getId() == loggedUserId)
                break;
            itr++;
        }
        cout<<"User: "<<itr->getLogin()<<", logged out."<<endl;
        loggedUserId=0;
        system("pause");
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
