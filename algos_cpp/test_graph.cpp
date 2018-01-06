#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    //adjastency list
    map<int, vector<int>> adj;

    vector<int> n1 = {2};
    adj.insert(make_pair(1, n1));
    adj[1].push_back(3);
    //create and add node 2's edges
    vector<int> n2 = {1, 3};
    adj.insert(make_pair(2, n2));

    vector<int> n3 = {2};
    adj.insert(make_pair(3, n3));

    for (int i=1; i <=3 ; i++)
    {
       cout << " Node" << i  << " : " ;
       auto v = adj[i];
       for (int j : adj[i]) {
           cout << j << " ";

       }
       cout << endl;
    }

}

