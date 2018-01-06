#include <bits/stdc++.h>

using namespace std;

int powerSum(int total, int power, int num) {
    int value = total - pow(num, power);
    if (value < 0) {
        return 0;
    }
    else if (value == 0) {
        return 1;
    }
    else return powerSum(total, power, num+1) + powerSum(total-pow(num,power), power, num+1);    
}

int main() {
    int X;
    cin >> X;
    int N;
    cin >> N;
    int result = powerSum(X, N, 1);
    cout << result << endl;
    return 0;
}

