#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;

int n, k, m, temp1, temp2;
int edge[31][31];
int x[31];
int ans;
int visited[31];

void Try(int btr){
    if (btr > k + 1){
        // for (int i = 1; i <= k + 1; ++i){
        //     cout << x[i] << ' ';
        // }
        // cout << endl;
        ++ans;
    } 
    else {
        for (int i = 1; i <= n; ++i){
            if (!visited[i] && edge[x[btr - 1]][i]){
                visited[i] = 1;
                x[btr] = i;
                Try(btr + 1);
                visited[i] = 0;
            }
        }
    }
}

void solution(int i){
    memset(visited, 0, sizeof visited);
    visited[i] = 1;
    x[1] = i;
    Try(2);
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k >> m;
    for (int i = 1; i <= m; ++i){
        cin >> temp1 >> temp2;
        edge[temp1][temp2] = edge[temp2][temp1] = 1;
    }
    //solution(1);
    for (int i = 1; i <= n; ++i){
        solution(i);
    }
    cout << ans / 2;
    
    
    return 0;
}
