#include <iostream>
#include <string>
using namespace std;

/*
*  Determines if a string has all unique characters
*  g++ test_unique.cpp -std=c++11
*/
bool has_unique(string & teststring) {
    int letters[256];
    for (char a : teststring) {
       unsigned int c = static_cast<unsigned int>(a);
       letters[c] += 1;
       if (letters[c] > 1) {
           return false;
       }
    }

    return false;
}

int main() {
    string my_teststring = "myteststring";
    cout << my_teststring << " has unique " << (has_unique(my_teststring)? "False" : "True") << endl; 
    return 0;
}

