#include <bits/stdc++.h>

using namespace std;

int subsetComponent(vector <long> d) {
    // Complete this function
}

int main() {
    int n;
    cin >> n;
    vector<long> d(n);
    for(int d_i = 0; d_i < n; d_i++){
       cin >> d[d_i];
    }
    int result = subsetComponent(d);
    cout << result << endl;
    return 0;
}
