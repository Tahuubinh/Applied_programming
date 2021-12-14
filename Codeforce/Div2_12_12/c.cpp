#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;
int t;

const int M = 2e5 + 1;
int n, k;
int x[M], neg[M], pos[M];

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> k;
        int ln = 0;
        int lp = 0;
        for (int i = 1; i <= n; ++i){
            cin >> x[i];
            if (x[i] <= 0){
                ++ln;
                neg[ln] = -x[i];
            } else {
                ++lp;
                pos[lp] = x[i];
            }
        }
        ll ans = 0;
        sort(neg+1, neg+1+ln);
        sort(pos + 1, pos + 1 + lp);
        // if (!ln){
        //     for (int i = k; i < lp; i += k){
        //         ans += pos[k] << 1;
        //     }
        //     ans += pos[lp];
        // } 
        // else if (!lp){
        //     for (int i = k; i < ln; i += k){
        //         ans += neg[k] << 1;
        //     }
        //     ans += neg[ln];
        // }
        if (neg[ln] > pos[lp]){
            int i;
            for (i = lp; i >= k; i -= k){
                ans += pos[i] << 1;
            }
            if (lp % k){
                ans += pos[lp % k] << 1;
            }
            for (i = ln - k; i >= k; i -= k){
                ans += neg[i] << 1;
            }
            if (ln % k){
                ans += neg[ln % k] << 1;
            }
            ans += neg[ln];
        }
        else {
            int i;
            for (i = ln; i >= k; i -= k){
                ans += neg[i] << 1;
            }
            if (ln % k){
                ans += neg[ln % k] << 1;
            }
            for (i = lp - k; i >= k; i -= k){
                ans += pos[i] << 1;
            }
            if (lp % k){
                ans += pos[lp % k] << 1;
            }
            ans += pos[lp];
        }
        cout << ans << endl;
    }

    
    return 0;
}
