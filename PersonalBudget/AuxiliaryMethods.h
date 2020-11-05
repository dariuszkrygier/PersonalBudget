#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include<cmath>
#include <ctime>

using namespace std;

class AuxiliaryMethods
{
public:
    static string convertIntToString(int number);
    static string loadLine();
    //static string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    //static int konwersjaStringNaInt(string liczba);
    static char loadChar();
    //static int wczytajLiczbeCalkowita();
    //static void usunPlik(string nazwaPlikuZRozszerzeniem);
    //static void zmienNazwePliku(string staraNazwa, string nowaNazwa);
    static string setCurrentDateOfTheOperation();
    static string setUsersDateOfTheOperation();
    static string convertDoubleToString(double number);
    static double convertStringToDouble(string numberAsString);

};

#endif
