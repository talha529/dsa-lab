#include <iostream>
#include <vector>
using namespace std;

const int N = 5;
vector<int> adj[N];
bool visited[N];

void dfsGraph(int node) {
    visited[node] = true;
    cout << node << " ";
    for (int i = 0; i < adj[node].size(); i++) {
        int neighbor = adj[node][i];
        if (!visited[neighbor]) dfsGraph(neighbor);
    }
}

int main() {
    for (int i = 0; i < N; i++) visited[i] = false;

    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);

    dfsGraph(0);
    return 0;
}

