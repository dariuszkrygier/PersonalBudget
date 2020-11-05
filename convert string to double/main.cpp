#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    string amountAsAString = "23423.123";
    stringstream ss;
        double amountAsADouble;
        ss << amountAsAString;
        ss >> amountAsADouble;

        cout << amountAsADouble;
    return 0;
}
