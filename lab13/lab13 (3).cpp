#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 5;
vector<int> adj[N];
bool visited[N];

void bfsGraph(int start) {
    queue<int> q;
    visited[start] = true;
    q.push(start);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for (int i = 0; i < adj[node].size(); i++) {
            int neighbor = adj[node][i];
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    for (int i = 0; i < N; i++) visited[i] = false;

    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);

    bfsGraph(0);
    return 0;
}

