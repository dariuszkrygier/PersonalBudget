#ifndef USERMANAGER_H
#define USERMANAGER_H
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <sstream>
#include "User.h"
#include "UsersFile.h"


using namespace std;

class UserManager
{
    int loggedUserId;
    vector <User> users;
    UsersFile usersFile;

    User specifyNewUserData();
    int getNewUserId();
    bool loginExists (string login);



public:
 UserManager (string usersFileName) : usersFile (usersFileName)
    {

         loggedUserId=0;
    users = usersFile.loadUsersFromFile();
   };
    void registerUser();
    int loginUser();
    void changePassword();
    void logoutUser();
    int getLoggedinUserId();
    bool isUserLoggedIn();
    void wypiszWszystkichUzytkownikow();

};

#endif
