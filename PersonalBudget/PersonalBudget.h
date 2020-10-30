#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include "UserManager.h"


using namespace std;

class PersonalBudget
{
UserManager userManager;

public:


    void registerUser();
    void loginUser();
    void changePassword();
    void logoutUser();
    void wypiszWszystkichUzytkownikow();
    bool isUserLoggedIn();
};
