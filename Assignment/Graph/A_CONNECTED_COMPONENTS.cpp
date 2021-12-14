#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;

const int M = 1e5 + 1;
int n, m, temp1, temp2;
vector<vector<int>> vt;
bool visited[M];
int ans;

void dfs(int i){
    if (!visited[i]){
        visited[i] = true;
        for (int j: vt[i]){
            dfs(j);
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    vt.resize(n + 1);
    for (int i = 1; i <= m; ++i){
        cin >> temp1 >> temp2;
        vt[temp1].push_back(temp2);
        vt[temp2].push_back(temp1);
    }
    for (int i = 1; i <= n; ++i){
        if (!visited[i]){
            ++ans;
            dfs(i);
        }
    }
    cout << ans;
    
    return 0;
}
