#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;

ll m = 998244353;
ll n, x;

ull powmod(ull a, ull b, ull m){
    a %= m;
    if (a == 0){
        return 0;
    }
    ull prod = 1;
    while (b){
        if (b & 1){
            prod *= a;
            prod %= m;
            --b;
        }      
        a*=a;
        a %= m;
        b/=2;
    }
    return prod;
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n >> x;
    ll res = powmod(x, n, m);
    for (int i = 1; i < x; ++i){
        res -= (powmod(i, n - 1, m) * (n % m));
        res %= m;
    }
    cout << res;

    
    return 0;
}
