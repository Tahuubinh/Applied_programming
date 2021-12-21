#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;

int m, n, u, v;
int edge[21][21];

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; ++i){
        cin >> u >> v;
        edge[u][v] = edge[v][u] = 1;
    }
    
    
    return 0;
}
