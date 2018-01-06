#include <iostream>
#include <vector>
#include <stack>
#include <map>

using namespace std;


bool dfs(map<int, vector<int>> adj,
         int source, 
         int destination) {

    bool target_found = false;
    bool *visited = new bool[adj.size() +1];
    for (int i = 0; i <= adj.size(); i++)
    {
        visited[i] = false;
    }
    stack<int> s;
    s.push(source);
    visited[source] = true;

    cout << "dfs ";
    
    while (!s.empty()) {
        int v = s.top();
        s.pop();
        cout << v << " ";
        if (v == destination) {
            target_found = true;
            break;
        }
        for (int n : adj[v]) {
            if (!visited[n]) {
               s.push(n);
               visited[n] = true;
            }
        }
    }
    delete[] visited;
    cout << endl;
    return target_found;
}

int main() {
map<int, vector<int>> adj;

vector<int>  n1 = {2, 3};

adj.insert(make_pair(1, n1));

vector<int> n2 = {1,4};
adj.insert(make_pair(2, n2));

vector<int> n3 = {1, 4};
adj.insert(make_pair(3, n3));

vector<int> n4 = {2, 3, 5, 6};
adj.insert(make_pair(4, n4));

vector <int> n5 = {4};
adj.insert(make_pair(5, n5));

vector<int> n6 = {4};
adj.insert(make_pair(6, n6));


cout << boolalpha << dfs(adj, 1, 5) << endl;
}
