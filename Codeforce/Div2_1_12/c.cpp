#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;
int t;

int n;
ll h;
int a[101];
ll b[101];

bool win(ll mid, ll h){
    h -= mid;
    for (int i = 1; i < n; ++i){
        h -= min(mid, b[i]);
    }
    return h <= 0;
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> h;
        for (int i = 1; i <= n; ++i){
            cin >> a[i];
        }
        for (int i = 1; i < n; ++i){
            b[i] = a[i + 1] - a[i];
        }
        ll l = h/n;
        ll r = h;
        ll mid;
        ll ans = r;
        while (l <= r){
            mid = (l + r) >> 1;
            if (win(mid, h)){
                r = mid - 1;
                if (mid < ans){
                    ans = mid;
                }
            } else{
                l = mid + 1;
            }
        }
        cout << ans << endl;
        //cout << win(2, h);
    }

    
    return 0;
}
