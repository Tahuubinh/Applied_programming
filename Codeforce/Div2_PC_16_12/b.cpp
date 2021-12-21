#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;
int t;

int n;

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        int a = n - 3;
        int b = 2;
        while (__gcd(a, b) != 1){
            --a;
            ++b;
        }
        cout << a << ' ' << b << ' ' << 1 << endl;
    }

    
    return 0;
}
