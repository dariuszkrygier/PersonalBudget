#include "PersonalBudget.h"

    void PersonalBudget :: registerUser()
    {
        userManager.registerUser();
    }
    void PersonalBudget :: loginUser()
    {
        userManager.loginUser();
    }
    void PersonalBudget :: changePassword()
    {
        userManager.changePassword();
    }
    void PersonalBudget :: logoutUser()
    {
        userManager.logoutUser();
    }
    void PersonalBudget :: wypiszWszystkichUzytkownikow()
    {
        userManager.wypiszWszystkichUzytkownikow();
    }
    bool PersonalBudget :: isUserLoggedIn()
    {
        return userManager.isUserLoggedIn();
    }
