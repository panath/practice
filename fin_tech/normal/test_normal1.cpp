#include <cmath>
#include <iostream>
using namespace std;

double normal(double mean, double sig, double x){
    return (1.0/2.0)*(1.0 + erf((x-mean)/(sig*pow(2.0,0.5))));
}

/*  
    1) scored higher than 80 (i.e. grade > 80)
    2) passed the test (i.e. grade >= 60)
    3) failed the test (i.e. have a grade < 60)
*/
int main() {
    cout.precision(2);
    cout<<fixed<<(1.0 - normal(70,10,80))*100.0<<endl;
    cout <<  (1.0-normal(70,10,60))*100.0  <<endl;
    cout <<normal(70,10,60)*100.0;
    cout << endl;
    return 0;
}
