#include "AuxiliaryMethods.h"
#include <sstream>


string AuxiliaryMethods :: convertIntToString(int number) {
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string AuxiliaryMethods :: loadLine() {
    string input = "";
    getline(cin, input);
    return input;
}
/*
string AuxiliaryMethods :: zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst) {
    if (!tekst.empty()) {
        transform(tekst.begin(), tekst.end(), tekst.begin(), ::tolower);
        tekst[0] = toupper(tekst[0]);
    }
    return tekst;
}

int AuxiliaryMethods :: konwersjaStringNaInt(string liczba) {
    int liczbaInt;
    istringstream iss(liczba);
    iss >> liczbaInt;

    return liczbaInt;
}
*/
char AuxiliaryMethods :: loadChar() {
    string input = "";
    char sign  = {0};

    while (true) {
        getline(cin, input);

        if (input.length() == 1) {
            sign = input[0];
            break;
        }
        cout << "This is not a single char, please try again." << endl;
    }
    return sign;
}
/*
int AuxiliaryMethods :: wczytajLiczbeCalkowita() {
    string wejscie = "";
    int liczba = 0;

    while (true) {
        getline(cin, wejscie);

        stringstream myStream(wejscie);
        if (myStream >> liczba)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return liczba;
}

void AuxiliaryMethods :: usunPlik(string nazwaPlikuZRozszerzeniem) {
    if (remove(nazwaPlikuZRozszerzeniem.c_str()) == 0) {}
    else
        cout << "Nie udalo sie usunac pliku " << nazwaPlikuZRozszerzeniem << endl;
}

void AuxiliaryMethods :: zmienNazwePliku(string staraNazwa, string nowaNazwa) {
    if (rename(staraNazwa.c_str(), nowaNazwa.c_str()) == 0) {}
    else
        cout << "Nazwa pliku nie zostala zmieniona." << staraNazwa << endl;
}
*/

string AuxiliaryMethods::setCurrentDateOfTheOperation() {
    time_t t = time(NULL);
    tm* tPtr = localtime(&t);

    int year, month, day;
    string yearString, monthString, dayString, date;



    year = (tPtr->tm_year)+1900;
    month = (tPtr->tm_mon)+1;
    day = (tPtr->tm_mday);

    yearString = convertIntToString(year);
    monthString = convertIntToString(year);
    if (monthString.length() == 1) {
        monthString = "0" + monthString;
    }
    dayString = convertIntToString(day);
    if (dayString.length() == 1) {
        dayString = "0" + dayString;
    }

    date = yearString + "-" + monthString + "-" + dayString;

    return date;
}

string AuxiliaryMethods :: setUsersDateOfTheOperation() {
    cout << "Please enter the date (yyyy-mm-dd): ";
    string date;
    date = AuxiliaryMethods :: loadLine();
    if (date.length() < 10 || date.length() > 10) {
        date = "0";
        return date;
    }

    return date;
}

string AuxiliaryMethods :: convertDoubleToString(double number) {
    std::ostringstream strs;
    strs << number;
    std::string str = strs.str();
    return str;
}

double AuxiliaryMethods :: convertStringToDouble(string numberAsString)
{

    stringstream ss;
        double number;
        ss << numberAsString;
        ss >> number;

    return number;
}
