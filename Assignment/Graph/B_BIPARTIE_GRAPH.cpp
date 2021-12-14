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
int color[M];

bool bfs(int btr){
    queue<int> q;
    q.push(btr);
    visited[btr] = 1;
    while(!q.empty()){
        int x = q.front(); 
        q.pop();
        for (int v: vt[x]){
            if (visited[v]){
                if (color[v] == color[x]){
                    return false;
                }
            } else {
                color[v] = 1 - color[x];
                q.push(v);
                visited[v] = 1;
            }
        }
    }
    return true;
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
        if (!visited[i]){
            if (!bfs(i)){
                cout << 0;
                return 0;
            }
        }
    }
    cout << 1;

    
    return 0;
}
