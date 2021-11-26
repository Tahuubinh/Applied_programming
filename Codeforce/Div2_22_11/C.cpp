#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;
int t;

ll k, x, mid, l, r, ans;

ll count(ll mid, ll k){
    ll sum;
    if (mid <= k){
        sum = (mid + 1) * mid / 2;
    } else{
        mid = 2 * k - 1 - mid;
        sum = k * k - (mid + 1) * mid / 2;
    }
    return sum;
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        cin >> k >> x;
        if (x == 1){
            cout << 1 << endl;
            continue;
        }
        l = 1, r = 2 * k - 1;
        ans = 1;
        while (l <= r){
            mid = (l + r) >> 1;
            if (count(mid, k) < x){
                l = mid + 1;
                if (ans < mid)
                    ans = mid;
            } else{
                r = mid - 1;
            }
        }
        if (ans == 2 * k - 1){
            cout << ans << endl;
        }
        else{
            cout << ans + 1 << endl;
        }
    }
    
    
    return 0;
}
