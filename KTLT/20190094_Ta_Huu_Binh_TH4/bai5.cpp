#include <bits/stdc++.h>
using namespace std;

void dfs(vector< list<int> > adj) {
    stack<int> S;
    vector<bool> visited(adj.size());
    S.push(1); // Bắt đầu từ đỉnh số 1
    
    visited[1] = true;
    cout << 1 << endl;
    while (!S.empty()){
        int u = S.top();
        if (!adj[u].empty()){
            int v = adj[u].front();
            adj[u].pop_front();
            if (!visited[v]){
                visited[v] = true;
                cout << v << endl;
                S.push(v);
            }
        } else {
            S.pop();
        }
    }
}

int main(){
    //ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n = 7;
    vector< list<int> > adj;
    adj.resize(n + 1);
    adj[1].push_back(2);
    adj[2].push_back(4);
    adj[1].push_back(3);
    adj[3].push_back(4);
    adj[3].push_back(5);
    adj[5].push_back(2);
    adj[2].push_back(7);
    adj[6].push_back(7);
    dfs(adj);
    
    
    return 0;
}
