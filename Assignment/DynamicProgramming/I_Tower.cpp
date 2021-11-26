#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;

int n, a, b, c, x[99], y[99], z[99], dp[99], dem;

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while(1){
        cin >> n;
        int n3 = 3*n;
        if (!n) break;
        ++dem;
        for (int i = 0; i < n; ++i){
            cin >> a >> b >> c;
            if (a > b){
                swap(a, b);
            }
            if (b > c){
                swap(b, c);
            }
            if (a > b){
                swap(a, b);
            }
            x[3*i + 1] = a;
            y[3*i + 1] = b;
            z[3*i + 1] = c;

            x[3*i + 2] = a;
            y[3*i + 2] = c;
            z[3*i + 2] = b;

            x[3*i + 3] = b;
            y[3*i + 3] = c;
            z[3*i + 3] = a;
        }
        for (int i = 1; i < n3; ++i){
            for (int j = i + 1; j <= n3; ++j){
                if (x[i] > x[j] && y[i] > y[j]){
                    swap(x[i], x[j]);
                    swap(y[i], y[j]);
                    swap(z[i], z[j]);
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n3; ++i){
            dp[i] = z[i];
            for (int j = 1; j < i; ++j){
                if (x[j] < x[i] && y[j] < y[i]){
                    dp[i] = max(dp[i], dp[j] + z[i]);
                }
            }
            if (dp[i] > ans){
                ans = dp[i];
            }
        }
        cout << "Case " << dem << ": maximum height = " << ans << endl;
    }
    
    
    return 0;
}
