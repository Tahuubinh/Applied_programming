#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;

const int N = 1e5 + 1;
int n, m, u, v, w, s, t;
vector<vector<int>> edge;
map<pii, int> weight;
int visited[N];
int length;
int ans = INT_MAX;
int D[N], P[N];

// void dfs(int u){
//     for (int v: edge[u]){
//         if (!visited[v]){
//             visited[v] = 1;
//             length += weight[{u, v}];
//             if (v == t){
//                 ans = min(length, ans);
//                 visited[v] = 0;
//                 length -= weight[{u, v}];
//                 continue;
//             }
//             dfs(v);
//             visited[v] = 0;
//             length -= weight[{u, v}];
//         }
//     }
// }

struct compare{
    bool operator() (pii a, pii b){
        return a.second > b.second;
    }
};

void dijkstra(int s){
    D[s] = 0;
    priority_queue<pii, vector<pii>, compare> q;
    for (int i = 1; i <= n; ++i){
        q.push({i, D[i]});
    }    

    for (int i = 0; i < n; ++i){
        pii x = q.top();
        q.pop();
        int ubest = x.first;
        P[ubest] = 1;

        for (int v: edge[ubest]){
            if (!P[v]){               
                D[v] = min(D[v], D[ubest] + weight[{ubest, v}]);
                q.push({v, D[v]});
            }
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        D[i] = INT_MAX;
    }
    edge.resize(n + 1);
    for (int i = 1; i <= m; ++i){
        cin >> u >> v >> w;
        edge[u].push_back(v);
        weight[{u, v}] = w;
    }
    cin >> s >> t;
    dijkstra(s);
    // for (int i = 1; i <= n; ++i){     
    //     cout << D[i] << endl;
    // }
    if (D[t] == INT_MAX){
        cout << -1;
        return 0;
    }
    cout << D[t];
    
    
    return 0;
}
