#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;

const int M = 10001;
int n, k, m;
int cost[M][M];
int even[M][M][3], odd[M][M][3];
int x, y, temp;

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k >> m;
    for (int i = 1; i <= m; ++i){
        cin >> x >> y >> temp;
        cost[x][y] = temp;
        cost[y][x] = temp;
    }
    
    
    return 0;
}
