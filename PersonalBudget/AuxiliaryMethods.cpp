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
*/
int AuxiliaryMethods :: convertStringToInt(string number) {
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}

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


string AuxiliaryMethods::setCurrentDateOfTheOperation() {
    time_t t = time(NULL);
    tm* tPtr = localtime(&t);

    int year, month, day;
    string yearString, monthString, dayString, date;



    year = (tPtr->tm_year)+1900;
    month = (tPtr->tm_mon)+1;
    day = (tPtr->tm_mday);

    yearString = convertIntToString(year);
    monthString = convertIntToString(month);
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
    string year = date.substr( 0, 4);
    int yearAsAnInteger;
    istringstream strYear(year);
    strYear >> yearAsAnInteger;
    string month = date.substr( 5, 2);
    int monthAsAnInteger;
    istringstream strMonth(month);
    strMonth >> monthAsAnInteger;
    string day = date.substr( 8, 2);
    int dayAsAnInteger;
    istringstream strDay(day);
    strDay >> dayAsAnInteger;
    bool hasTheDateCorrectFormat = checkTheFormatOfTheDate(yearAsAnInteger, monthAsAnInteger, dayAsAnInteger);
    if (hasTheDateCorrectFormat == true) {
        return date;
    } else {
        date = "0";
        return date;
    }
}
bool AuxiliaryMethods::checkTheFormatOfTheDate(int yearAsAnInteger, int monthAsAnInteger, int dayAsAnInteger) {
    bool hasTheDateCorrectFormat = true;
    switch(monthAsAnInteger) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if (dayAsAnInteger < 1 || dayAsAnInteger > 31) {
            hasTheDateCorrectFormat = false;
            return hasTheDateCorrectFormat;
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if (dayAsAnInteger < 1 || dayAsAnInteger > 30) {
            hasTheDateCorrectFormat = false;
            return hasTheDateCorrectFormat;
        }
        break;
    case 2:
        if (((yearAsAnInteger%4 == 0) && (yearAsAnInteger%100 != 0)) || (yearAsAnInteger%400 == 0)) {
            if (dayAsAnInteger < 1 || dayAsAnInteger > 29) {
                hasTheDateCorrectFormat = false;
                return hasTheDateCorrectFormat;
            }
        } else {
            if (dayAsAnInteger < 1 || dayAsAnInteger > 28) {
                hasTheDateCorrectFormat = false;
                return hasTheDateCorrectFormat;
            }
        }
        break;
    }
    if ((yearAsAnInteger < 2000) || (monthAsAnInteger < 1) || (monthAsAnInteger > 12)) {
        hasTheDateCorrectFormat = false;
        return hasTheDateCorrectFormat;
    }
    return hasTheDateCorrectFormat;
}


string AuxiliaryMethods :: convertDoubleToString(double number) {
    std::ostringstream strs;
    strs << number;
    std::string str = strs.str();
    return str;
}

double AuxiliaryMethods :: convertStringToDouble(string numberAsString) {

    stringstream ss;
    double number;
    ss << numberAsString;
    ss >> number;

    return number;
}

string AuxiliaryMethods :: removeChosenCharacterFromString (string dateAsString) {
    dateAsString.erase(remove(dateAsString.begin(), dateAsString.end(), '-'), dateAsString.end()); //remove - from string
    return dateAsString;
}

int AuxiliaryMethods :: getCurrentYear() {
    SYSTEMTIME localTime;
    GetLocalTime(&localTime);
    int year = localTime.wYear;

    return year;
}

int AuxiliaryMethods :: getCurrentMonth() {
    SYSTEMTIME localTime;
    GetLocalTime(&localTime);
    int month = localTime.wMonth;

    return month;
}

int AuxiliaryMethods :: getYearFromOperationDate(string date) {
    string year = date.substr( 0, 4);
    int yearAsAnInteger;
    istringstream strYear(year);
    strYear >> yearAsAnInteger;

    return yearAsAnInteger;
}

int AuxiliaryMethods :: getMonthFromOperationDate(string date) {
    string month = date.substr( 5, 2);
    int monthAsAnInteger;
    istringstream strMonth(month);
    strMonth >> monthAsAnInteger;

    return monthAsAnInteger;
}
