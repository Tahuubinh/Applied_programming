#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;

const int N = 1e5 + 1;
int n;
int u, v, w;
vector<vector<int>> edge;
map<pii, int> weight;
int visited[N];
int length, ans;
int end1;

void dfs(int btr){
    for (int v: edge[btr]){
        if (!visited[v]){
            visited[v] = 1;
            length += weight[{btr, v}];
            if (length > ans){
                ans = length;
                end1 = v;
            }
            dfs(v);
            visited[v] = 0;
            length -= weight[{btr, v}];
        }
    }
}

void solve(int btr){
    memset(visited, 0, sizeof visited);
    visited[btr] = 1;
    length = 0;
    dfs(btr);
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    edge.resize(n + 1);
    for (int i = 1; i < n; ++i){
        cin >> u >> v >> w;
        edge[u].push_back(v);
        edge[v].push_back(u);
        weight[{u, v}] = w;
        weight[{v, u}] = w;
    }
    // for (int u = 1; u <= n; ++u){
    //     // for (int v: edge[u]){
    //     //     cout << v << ": " << weight[{u, v}] << ", ";
    //     // }
    //     // cout << endl;
    //     solve(u);
    //     //cout << ans << endl;
    // }
    solve(1);
    solve(end1);
    cout << ans;
    
    
    return 0;
}
