#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;

const int M = 1e5 + 1;
int n, m, temp1, temp2;
vector<int> edge[M];
int connect[M], low[M], num[M];
int ans, cnt;
stack<int> st;

void dfs(int u){
    low[u] = num[u] = ++cnt;
    st.push(u);
    connect[u] = 1;
    for (int v: edge[u]){
        if (!num[v]){
            dfs(v);
        } 
        if (connect[v]){
            low[u] = min(low[u], low[v]);
        }
    }

    if (num[u] == low[u]){
        ++ans;
        while(true){
            int v = st.top();
            st.pop();
            connect[v] = 0;
            if (u == v){
                break;
            }
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    //edge.resize(n + 1);
    for (int i = 1; i <= m; ++i){
        cin >> temp1 >> temp2;
        edge[temp1].push_back(temp2);
    }
    for (int i = 1; i <= n; ++i){
        if (!num[i]){
            dfs(i);
        }
    }
    cout << ans;
    
    return 0;
}
