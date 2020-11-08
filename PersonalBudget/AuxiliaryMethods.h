#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include<cmath>
#include <ctime>
#include <windows.h>
#include "Income.h"
#include "Expense.h"

using namespace std;

class AuxiliaryMethods {
public:
    static string convertIntToString(int number);
    static string loadLine();
    //static string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    static int convertStringToInt(string number);
    static char loadChar();
    static string setCurrentDateOfTheOperation();
    static string setUsersDateOfTheOperation();
    static bool checkTheFormatOfTheDate(int yearAsAnInteger, int monthAsAnInteger, int dayAsAnInteger);
    static string convertDoubleToString(double number);
    static double convertStringToDouble(string numberAsString);
    static string removeChosenCharacterFromString (string dateAsString);
    static int getCurrentYear();
    static int getCurrentMonth();
    static int getYearFromOperationDate(string date);
    static int getMonthFromOperationDate(string date);

};

#endif
