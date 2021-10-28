#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;
int t;

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

ull inv(ull a, ull m){
    return powmod(a, m - 2, m);
}

ull fact(ull n, ull m){
    ull fact = 1;
    for (ull i = 2; i <= n; ++i){
        fact = fact * (i % m);
        fact %= m;
    }
    return fact;
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        ull n, k, m;
        cin >> n >> k >> m;
        ull res = 1;
        if (k > n/2){
            k = n - k;
        }
        for (ull i = n; i >= n - k + 1; --i){
            res *= (i % m);
            res %= m;
        }
        res *= inv(fact(k, m), m);
        cout << res % m << endl;
    }
    // for (int i = 0; i <= 10; ++i){
    //     cout << fact(i, 50) << endl;
    // }
    
    
    return 0;
}
