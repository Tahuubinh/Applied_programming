#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;

const int M = 1e6 + 1;
int n;
ll a[M], dp[M];

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    dp[1] = a[1];
    for (int i = 2; i <= n; ++i){
        dp[i] = max(a[i], a[i] + dp[i - 1]);
    }
    // for (int i = 1; i <= n; ++i){
    //     cout << dp[i] << ' ';
    // }
    cout << *max_element(dp + 1, dp + 1 + n);
    return 0;
}
