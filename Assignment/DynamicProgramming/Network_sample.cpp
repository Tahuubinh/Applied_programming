#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

const int oo =1e9;
int m,n,k;
int a,b,w;
vector <pii> adj[10001];
int d[10001][2001];
int res = oo;
int parent[10001];

void DFS(int u)
{   
    for(int i = 1;i<=k;i++) d[u][i]= oo;
    d[u][0] = 0;
    for(pii node: adj[u])
    {
        int v= node.second;
        int val = node.first;
        if(parent[u]==v) continue;
        parent[v]=u;
        DFS(v);
        for(int j = 0;j<=k-1;j++)
            res = min(res, d[u][j]+d[v][k-j-1]+val);
        for(int j = 1; j<=k;j++)
        {
            d[u][j] = min (d[u][j], d[v][j-1]+val);
        }
        res= min(res,d[u][k]);
    }
}

int main()
{
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>k>>m;
    for (int i = 1; i <= m; ++i){
        cin >> a >> b >> w;
        adj[a].push_back(pii(w, b));
        adj[b].push_back(pii(w, a));
    }
    
    DFS(1);
    cout<<res;
    return 0;
}