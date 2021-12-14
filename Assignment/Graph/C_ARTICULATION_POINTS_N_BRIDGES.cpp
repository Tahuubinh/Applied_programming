#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;

const int M = 1e5 + 1;
int n, m, temp1, temp2;
vector<vector<int>> vt;
bool num[M], low[M], pa[M], cnt;

void dfs(int u){
    num[u] = ++cnt;
    low[u] = INT_MAX;
    for (int v: vt[u]){
        if (v != pa[u]){
            if (num[v]){
                low[u] = min(low[u], num[v]);
            }
            else {
                pa[v] = u;
                dfs(v);
                low[u] = min(low[u], low[v]);
            }
        }
    }
}

void countArti(){
    int arti[n] = {0};
    int child[n] = {0};
    for (int v = 1; v <= n; ++v){
        int u = pa[v];
        if (u){
            
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    vt.resize(n + 1);
    for (int i = 0; i < m; ++i){
        cin >> temp1 >> temp2;
        vt[temp1].push_back(temp2);
        vt[temp2].push_back(temp1);
    }

    
    return 0;
}
