#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;

int n, m, num[10005], low[10005], temp1, temp2,
cnt=0, connect[10005], numSCC=0;
vector<int> a[10005];
stack<int> S;

// void dfs(int u) {
//     low[u] = num[u] = ++cnt;
//     S.push(u);
//     connect[u] = 1;
//     for(int v : a[u]) {
//         if (!num[v]) dfs(v);
//         if (connect[v]) low[u] = min(low[u], low[v]);
//     }

//     if (num[u] == low[u]) {
//         numSCC++;
//         while(1) {
//             int v = S.top(); S.pop();
//             connect[v] = 0;
//             if (u == v) break;
//         }
//     }
// }

void dfs(int u){
    low[u] = num[u] = ++cnt;
    S.push(u);
    connect[u] = 1;
    for (int v: a[u]){
        if (!num[v]){
            dfs(v);
        } 
        if (connect[v]){
            low[u] = min(low[u], low[v]);
        }
    }

    if (num[u] == low[u]){
        ++numSCC;
        while(true){
            int v = S.top();
            S.pop();
            connect[v] = 0;
            if (u == v){
                break;
            }
        }
    }
}

int main() {

    // cin >> n >> m;
    // for(int i = 0; i < m; i++) {
    //     int u, v; cin >> u >> v;
    //     a[u].push_back(v);
    // }

    // // memset(num, 0, sizeof num);
    // // memset(low, 0, sizeof low);
    // // memset(connect, 0, sizeof connect);
    // for(int u = 1; u <= n; u++)
    //     if (!num[u]) dfs(u);

    // cout << numSCC;

    cin >> n >> m;
    //a.resize(n + 1);
    for (int i = 1; i <= m; ++i){
        cin >> temp1 >> temp2;
        a[temp1].push_back(temp2);
    }
    for (int i = 1; i <= n; ++i){
        if (!num[i]){
            dfs(i);
        }
    }
    cout << numSCC;

    return 0;
}