#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;
int t;

int n, k;
int a[11];
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
        int ind = 1;
        while (k >= (power[a[ind + 1] - a[ind]] - 1) && ind < n){
            ll temp = power[a[ind + 1] - a[ind]] - 1;
            k -= temp;
            ans += power[a[ind]] * temp;
            ind++;
        }
        cout << ans + power[a[ind]] * (k + 1) << endl;
    }

    
    return 0;
}
