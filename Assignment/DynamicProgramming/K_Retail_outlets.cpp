#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;

const int MOD = 1e9 + 7;
int n, m;
int a[101];
ll dp[101][501];

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    for (int k = a[1]; k <= m; k = k + a[1]){
        dp[1][k] = 1;
    }
    for (int i = 2; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            // Every element in a should appears
            for (int k = a[i]; k <= j; k = k + a[i]){
                dp[i][j] += dp[i - 1][j - k];
                dp[i][j] %= MOD;
            }
        }
    }
    // for (int i = 1; i <= n; ++i){
    //     for (int j = 1; j <= m; ++j){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    cout << dp[n][m];
    
    return 0;
}
