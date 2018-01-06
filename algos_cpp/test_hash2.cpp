#include <iostream>
#include <string>
#include <vector>

using namespace std;


/*
Test hash function which returns 0 or 1
Based on parrity (odd/even) of the sum of characters in the string
*/
int hashfunc(string s) {
   int ret = 0;

   for (char c : s) {
       ret += c;
   }

   return (ret & 1);
}


void hashset_insert(vector<string> hs[],
                    string s) {
    int i = hashfunc(s);
    for (string c : hs[i]) {
        if (s == c)
            return;
    }

    hs[i].push_back(s);
}

bool hashset_contains(vector<string> hs[],
                      string s) 
{
    int i = hashfunc(s);
    for (string c : hs[i]) {
        if (s == c)
            return true;
    }
    return false;
}

int main() {

    string hs[2];
    hs[hashfunc("yes")] = "yes";
    hs[hashfunc("no")] = "no";
    hs[hashfunc("maybe")] = "maybe";
   
    cout << "yes :" << hs[hashfunc("yes")] << endl;
    cout << "no : " << hs[hashfunc("no")] << endl;
    cout << "maybe : " << hs[hashfunc("maybe")] << endl;


    vector<string> hs2[2];
    hashset_insert(hs2, "yes");
    hashset_insert(hs2, "no");
    hashset_insert(hs2, "maybe");

    cout << boolalpha << hashset_contains(hs2, "yes") << endl;
    cout << boolalpha << hashset_contains(hs2, "no") << endl;
    cout << boolalpha << hashset_contains(hs2, "maybe") << endl;
}
