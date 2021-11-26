#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;

int n;
int a[10001], dp[10001];

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        dp[i] = 1;
    }
    for (int i = 2; i <= n; ++i){
        for (int j = 1; j < i; ++j){
            if (a[j] < a[i] && dp[j] >= dp[i]){
                dp[i] = dp[j] + 1;
            }
        }
    }
    cout << *max_element(dp + 1, dp+1+n);
    
    return 0;
}
