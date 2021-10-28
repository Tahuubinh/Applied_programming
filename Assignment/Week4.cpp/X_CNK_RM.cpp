#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;

const ull M = 1e9 + 7;
ull n, k;
 
ull powmod(ull a, ull b){
    a %= M;
    if (a == 0){
        return 0;
    }
    ull prod = 1;
    while (b){
        if (b & 1){
            prod *= a;
            prod %= M;
            --b;
        }      
        a*=a;
        a %= M;
        b/=2;
    }
    return prod;
}

ull inv(ull a){
    return powmod(a, M - 2);
}
 
int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> k >> n;
    if (k > n/2){
        k = n - k;
    }
    ull res = 1;
    for (ull i = 1; i <= k; ++i){
        res *= inv(i) * (n + 1 - i);
        res %= M;
    }
    cout << res;
    
    
    return 0;
}