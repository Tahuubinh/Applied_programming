#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;

const int M = 2e3 + 1;
int n, m, temp1, temp2;
vector<vector<int>> vt;
bool visited[M];
int color[M];
int t;
int scene = 0;

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
    cin >> t;

    while (t--){
        ++scene;
        cin >> n >> m;
        vt.clear();
        vt.resize(n + 1);
        memset(visited, 0, sizeof visited);
        memset(color, 0, sizeof color);
        for (int i = 0; i < m; ++i){
            cin >> temp1 >> temp2;
            vt[temp1].push_back(temp2);
            vt[temp2].push_back(temp1);
        }
        int end = 0;
        for (int i = 1; i <= n; ++i){
            if (!visited[i]){
                if (!bfs(i)){
                    cout << "Scenario #" << scene << ':' << endl;
                    cout << "Suspicious bugs found!" << endl;
                    end = 1;
                    break;
                }
            }
        }
        if (end){
            continue;
        }
        cout << "Scenario #" << scene << ':' << endl;
        cout << "No suspicious bugs found!" << endl;
    }

    
    return 0;
}
