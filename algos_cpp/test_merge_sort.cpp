#include <iostream>

using namespace std;

/*
 outputs array
*/
void output(int a[], int size) {

    for (int i=0; i< size; i++)
    {
       cout << a[i] << " ";
    }

    cout << endl;
}

void merge_sort(int a[], int size) {

}

int main() {
   int a[10] = {8, 4, 1, 5, 10, 7, 6, 2, 9, 3};
   int aux[10];

   output(a, sizeof(a)/sizeof(a[0]));


   output(a, sizeof(a)/sizeof(a[0]));
}
