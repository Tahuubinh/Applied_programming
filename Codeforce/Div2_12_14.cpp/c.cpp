#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;
int t;

int n;
ll a[101];

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        for (int i = 1; i <= n; ++i){
            cin >> a[i];
        }
        ll gcd1 = a[1];
        ll gcd2 = a[2];
        for (int i = 3; i <= n; i+=2){
            gcd1 = __gcd(gcd1, a[i]);
        }
        for (int i = 4; i <= n; i+=2){
            gcd2 = __gcd(gcd2, a[i]);
        }
        //cout << gcd1 << ' ' << gcd2 << endl;
        int end = 0;
        for (int i = 1; i <= n; i+=2){
            if (a[i] % gcd2 == 0){
                end = 1;
                break;
            }
        }
        if (!end){
            cout << gcd2 << endl;
            continue;
        }
        //cout << end;
        end = 0;
        for (int i = 2; i <= n; i+=2){
            if (a[i] % gcd1 == 0){
                end = 1;
                break;
            }
        }
        if (!end){
            cout << gcd1 << endl;
            continue;
        }
        cout << 0 << endl;
        continue;
    }

    
    return 0;
}
