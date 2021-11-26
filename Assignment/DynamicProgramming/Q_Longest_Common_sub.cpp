#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;

const int M = 1e4 + 1;
int n, m, ans;
int x[M], y[M];
int dp[M][M];

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        cin >> x[i];
    }
    for (int i = 1; i <= m; ++i){
        cin >> y[i];
    }
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            if (x[i] == y[j]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j -1]);
            }
            if (dp[i][j] > ans){
                ans = dp[i][j];
            }
        }
    }
    cout << ans;

    return 0;
}
