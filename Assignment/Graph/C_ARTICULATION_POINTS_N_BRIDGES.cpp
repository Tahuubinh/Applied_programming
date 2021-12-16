#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;

const int M = 1e5 + 1;
int n, m, temp1, temp2;
vector<vector<int>> vt;
int num[M], low[M], pa[M], cnt;
int arti[M], child[M];

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

void checkArti(){
    for (int v = 1; v <= n; ++v){
        int u = pa[v];
        if (u){
            ++child[u];
        }
    }
    for (int v = 1; v <= n; ++v){
        int u = pa[v];
        if (u && pa[u] && low[v] >= num[u]){
            arti[u] = 1;
        }
    }
    for (int u = 1; u <= n; ++u){
        if (pa[u] == 0 && child[u] >= 2){
            arti[u] = 1;
        }
    }
}

int cntBridge(){
    int cnt = 0;
    for (int v = 1; v <= n; ++v){
        cnt += (pa[v] && low[v] >= num[v]);
    }
    return cnt;
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
    for (int i = 1; i <= n; ++i){
        if (!num[i]){
            dfs(i);
        }
    }
    checkArti();
    int cntArti = 0;
    cntArti = accumulate(arti+1, arti+1+n, cntArti);
    cout << cntArti << ' ' << cntBridge() << endl;
    
    return 0;
}
