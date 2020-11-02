#ifndef USERSFILE_H
#define USERSFILE_H
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "User.h"
#include "AuxiliaryMethods.h"
#include <stdio.h>
#include "Markup.h"


using namespace std;

class UsersFile
{
    const string usersFileName;

public:
    UsersFile(string USERSFILENAME) : usersFileName (USERSFILENAME) {};
    vector <User> loadUsersFromFile();
    void saveUserToFile(User user);
    void saveAllUsersToFile(vector <User> &users);
};

#endif
