#include<iostream>
#include<algorithm>

using namespace std;
main() {
   string my_str = "2020-10-12";

   cout << "Initial string: " << my_str << endl;

   my_str.erase(remove(my_str.begin(), my_str.end(), '-'), my_str.end()); //remove - from string
   cout << "Final string: " << my_str;
}
