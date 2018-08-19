#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
/*
# Enter your code here. Read input from STDIN. Print output to STDOUT
x = [95, 85, 80, 70, 60]
y = [85, 95, 70, 65, 70]
ax = sum(x)/len(x)
ay = sum(y)/len(y)
sx = 0
n = 0
d = 0

for i in range(len(x)):
    n += (ax-x[i])*(ay-y[i])
    d += (ax-x[i])**2 

slope = (1.0*n)/d
inter = ay - slope*ax
y = slope*80+inter
print (round(y,3))
*/

int main() {
    std::vector<int> x = {95, 85, 80, 70, 60};
    std::vector<int> y = {95, 85, 80, 70, 60};
    int n = x.size();
    double sxi = 0.0;
    double sxi2 = 0.0;
    double syi = 0.0;
    double sxi_syi = 0.0;
    
    for (int  i=0; i < n; i++) {
        sxi += x[i];
        syi += y[i];
        sxi_syi += x[i] * y[i];
        sxi2 += pow(x[i], 2);
    }
    double b =  ((n * sxi_syi) - (sxi*syi)) / ((n*sxi2)  + (sxi*sxi));
    double a = (syi/n) - b * (sxi/n);
    cout.precision(3);
    cout << (a + (80.0* b)) << endl;
    return 0;
}

