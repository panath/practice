#include <iostream>

using namepsace std;

int main() {
    //Adjacency Matrix
    int adj[3][3] = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };

    for (int i=0; i < 3; i++)
    {
        cout << "Node " << (i+1) << ": ";
        for (int j=0; j < 3; j++)
        {
            if (adj[i][j] != 0)
            {
                cout << (j + 1) << " ";  
            }
        }
    }
}
