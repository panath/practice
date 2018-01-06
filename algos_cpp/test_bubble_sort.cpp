#include <iostream>


using namespace std;


/*
  output of array
*/ 
void output(int a[], int size)
{
    bool has_swapped  = true;

    for (int i=0; i < size; i++)
    {
        cout << a[i] << ' ';
    }

    cout << endl;
}

/*
  bubble sort algorithm
  Running time O(n^2)
*/
void bubble_sort(int a[], int size)
{
    bool has_swapped = true;

    for (int j=0; j < size-1 && has_swapped ; j++)
    {

        if (a[j] > a[j+1]) {
             int aux = a[j];
             a[j] = a[j+1];
             a[j+1] = aux;
             has_swapped = true;
        }

        output(a, size);
    }
}

int main() {
    int a[] = {5, 9, 4, 7, 1, 2, 8, 6, 3};
    output(a, 9);
    bubble_sort(a, 9);
    cout << endl;
    output(a, 9);

    return 0;
}
