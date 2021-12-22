#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;

const int N = 1e5 + 1;
vector<vector<int>> edge;
int n, u, v;
int p[N], notl[N];
queue<int> q;

void bfs(int start){
    q.push(start);
    p[1] = 1; // for visited
    while (!q.empty()){
        u = q.front();
        q.pop();
        for (int v: edge[u]){
            if (!p[v]){
                p[v] = u;
                q.push(v);
            }
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    edge.resize(n + 1);
    for (int i = 1; i < n; ++i){
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    bfs(1);
    for (int i = 1; i <= n; ++i){
        notl[p[i]] = 1;
    }
    int ans = 0;
    ans = accumulate(notl+1, notl+1+n, ans);
    cout << n - ans;

    
    
    
    return 0;
}
