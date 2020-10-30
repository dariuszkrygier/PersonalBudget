#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include "User.h"
//#include "PlikZUzytkownikami.h"
using namespace std;

class UserManager
{
    int loggedUserId;
    vector <User> users;

    User specifyNewUserData();
    int getNewUserId();
    bool loginExists (string login);
   // UsersFile usersFile;


public:
    UserManager ()//(string usersFileName) : usersFile (usersFileName) {
    {
         loggedUserId=0;
    }

    //users = usersFile.loadUsersFromFile();
   // };
    void registerUser();
    int loginUser();
    void changePassword();
    void logoutUser();
    int getLoggedinUserId();
    bool isUserLoggedIn();
    void wypiszWszystkichUzytkownikow();

};
