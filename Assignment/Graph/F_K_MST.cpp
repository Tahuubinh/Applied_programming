#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;

const int N = 21;
int n, m, k, u, v, w;
int edge[N][N], visited[N], x[N];
int ans = INT_MAX;
int total;

void Try(int btr){
    if (btr > k){
        ans = min(ans, total);
    }
    else {
        for (int i = 1; i <= n; ++i){
            if (!visited[i] && edge[x[btr - 1]][i]){
                visited[i] = 1;
                total += edge[x[btr - 1]][i];
                x[btr] = i;
                Try(btr + 1);
                total -= edge[x[btr - 1]][i];
                visited[i] = 0;
            }
        }
    }
}

void solution(int u){
    x[0] = u;
    total = 0;
    memset(visited, 0, sizeof visited);
    visited[u] = 1;
    Try(1);
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; ++i){
        cin >> u >> v >> w;
        edge[u][v] = edge[v][u] = w;
    }
    for (int i = 1; i <= n; ++i){
        solution(i);
    }
    cout << ans;
    
    
    return 0;
}
