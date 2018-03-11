#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void mergeFunction(int a[], int b[], int n, int m ){
    int k = m + n -1;
    int i = n-1;
    int j = m-1;

    while (i >=0 && j >= 0) {
        if (a[i] > b[j]) 
            a[k--] = a[i--];
        else
            a[k--] = b[j--];
    }

    while (j >= 0)
        a[k--] = b[j--];

}

int main() {

int a[] = {1, 2, 3, 4, 0, 0, 0, 0};
int b[] = {3, 5, 6, 9};
mergeFunction(a, b, 4, 4);


for (auto i : a) {
  std::cout << i  << " " ;
}
std::cout << endl;
}
