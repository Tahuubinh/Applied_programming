#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;
int t;

ll n, k;
ll a[11];
ll power[11];

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> k;
        power[0] = 1;
        for (int i = 1; i <= 10; i++){
            power[i] = 10 * power[i - 1];
        }
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        ll ans = 0;
        ll index = 1;
        while (index < n && k >= (power[a[index + 1] - a[index]] - 1)){
            ll temp = power[a[index + 1] - a[index]] - 1;
            k -= temp;
            ans += power[a[index]] * temp;
            ++index;
        }
        cout << ans + power[a[index]] * (k + 1) << endl;
    }

    
    return 0;
}
