#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
/*
# Enter your code here. Read input from STDIN. Print output to STDOUT
import math

def less_than_boundary_cdf(x, mean, std):
    return round(0.5 * (1 + math.erf((x - mean)/ (std * math.sqrt(2)))), 4)

print less_than_boundary_cdf(9800, 49 * 205, math.sqrt(49) * 15)
*/


double normal(double mean, double sig, double x){
    return (1.0/2.0)*(1.0 + erf((x-mean) / (sig*pow(2.0, 0.5))));
}

int main() {
    double mean = 9800.0;
    double sig = 15  * pow(49, 0.5);
    double x = 49 * 205.0;
    cout.precision(4);
    cout <<  normal(mean, sig, x)  << endl;
    return 0;
}

