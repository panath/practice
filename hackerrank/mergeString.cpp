#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int t=0;t<n;t++){
        string s1, s2;
        cin >> s1;
        cin >> s2;
        string letters = "abcdefghijlkmnopqrstuvwxyz";
        string output = "NO";
        //for (int i=0;i<letters.size();i++){
        for (char letter : s1){
            if (s2.find(letter) != string::npos){
                output = "YES";
                break;
            }
        }
        cout << output << endl;
    }
    return 0;
}
