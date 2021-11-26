#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;

int n, L1, L2;
ll a[100001];
ll b[100001];
int c;
ll ans;

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> L1 >> L2;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    ll maxa = a[1];
    for (int i = 1; i <= L1; ++i){
        if (a[i] > maxa){
            maxa = a[i];
        }
        b[i] = maxa;
    }
    ans = maxa;
    for (int i = L1 + 1; i <= n; ++i){
        maxa = b[i - L1];
        c = max(1, i - L2);
        for (int j = i - 1 - L1; j >= c; --j){
            if (b[j] > maxa){
                maxa = b[j];
            }
        }
        b[i] = maxa + a[i];
        if (b[i] > ans){
            ans = b[i];
        }
    }
    cout << ans;
    // for (int i = 1; i <= n; ++i){
    //     cout << b[i] << endl;
    // }
    
    return 0;
}
