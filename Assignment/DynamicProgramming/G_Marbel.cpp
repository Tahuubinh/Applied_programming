#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;

int W, H, n;
int w[201], h[201];
int ans[601][601];

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> W >> H >> n;
    for (int i = 1; i <= n; ++i){
        cin >> w[i] >> h[i];
    }
    for (int i = 1; i <= W; ++i){
        for (int j = 1; j <= H; ++j){
            ans[i][j] = i * j; // At the beginning
            for (int k = 1; k <= n; ++k){
                if (!(i % w[k]) && !(j % h[k])){
                    ans[i][j] = 0;
                    goto label;
                }
            }
            for (int k = 1; k < i; ++k){
                ans[i][j] = min(ans[i][j], ans[k][j] + ans[i - k][j]);
            }
            for (int k = 1; k < j; ++k){
                ans[i][j] = min(ans[i][j], ans[i][k] + ans[i][j - k]);
            }
            label:
                continue;
        }
    }
    cout << ans[W][H];
    return 0;
}
