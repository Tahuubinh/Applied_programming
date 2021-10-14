#include <bits/stdc++.h>
using namespace std;

int a[905][905];
int dist[905][905];
int m, n, i0, jj;


int bfs(int x, int y, queue<pair<int, int>> q){
    if (x == 1 || x == n || y == 1 || y ==m){
        return dist[x][y] + 1;
    }

    if (x > 1 && a[x - 1][y] == 0){
        q.push({x - 1, y});
        dist[x - 1][y] = dist[x][y] + 1;
        a[x - 1][y] = 1;
    }
    if (x < n && a[x + 1][y] == 0){
        q.push({x + 1, y});
        dist[x + 1][y] = dist[x][y] + 1;
        a[x + 1][y] = 1;
    }
    if (y > 1 && a[x][y - 1] == 0){
        q.push({x, y - 1});
        dist[x][y - 1] = dist[x][y] + 1;
        a[x][y - 1] = 1;
    }
    if (y < n && a[x][y + 1] == 0){
        q.push({x, y + 1});
        dist[x][y + 1] = dist[x][y] + 1;
        a[x][y + 1] = 1;
    }

    if (q.empty()){
        return -1;
    }
    pair<int, int> temp = q.front();
    q.pop();
    return bfs(temp.first, temp.second, q);
}
// int bfs(int x, int y){
//     cout << 2;
//     return 0;
// }

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    queue<pair<int,int>> q;
    cin >> n >> m;
    cin >> i0 >> jj;
    for (int i = 1; i<=n; ++i){
        for (int j = 1; j<=m; ++j){
            cin >> a[i][j];
        }
    }
    cout << bfs(i0, jj, q);

    
    return 0;
}