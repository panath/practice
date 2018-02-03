#include <iostream>

using namespace std;

int fibo(int n);

int main() {
    int n;
    cout << "Give fibo " << endl;
    cin >> n;
    cout << "fibo is " << fibo(n)  << endl; 

}


int fibo(int n) {

    if (n < 0) {
        return -1;
    }
    else if (n==0) {
        return 0;
    }
    else if (n==1) {
        return 1;
    }
    else if (n > 1) {
        return fibo(n-1) + fibo(n-2);
    }
    else 
        return -1;
}
