#include <iostream>
#include <sstream>

using namespace std;

int main()
{

double    dbl = 2344.54645;
    std::ostringstream strs;
strs << dbl;
std::string str = strs.str();
cout << str;
    return 0;
}
