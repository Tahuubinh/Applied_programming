#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;

int N, T, D;
int a[1001], t[1001];
int dp[1001][101];

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> T >> D;
    for (int i = 1; i <= N; ++i){
        cin >> a[i];
    }
    for (int i = 1; i <= N; ++i){
        cin >> t[i];
    }
    int ans = 0;
    for (int i = 1; i <= N; ++i){
        for (int j = 1; j <= T; ++j){
            if (j < t[i]){
                continue;
            }
            int far = max(0, i - D);
            for (int k = far; k < i; ++k){
                dp[i][j] = max(dp[i][j], dp[k][j - t[i]] + a[i]);
            }
            if (ans < dp[i][j]){
                ans = dp[i][j];
            }
        }
    }
    cout << ans;

    return 0;
}
