#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;
int t;

int n, m, mdu, ndu, mt, nt;

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> m;
        if (n == 1){
            cout << (m + 2) / 3 << endl;
            continue;
        }
        if (m == 1){
            cout << (n + 2) / 3 << endl;
            continue;
        }
        // mt = m / 3 * 3;
        // nt = n /3 * 3;
        // mdu = m % 3;
        // ndu = n % 3;
        // int ans = nt * mdu;
        // if (mdu == 1){
        //     ans += (n + 2) / 3 << endl;
        // } else{
        //     ans += min( n*((mdu + 2) / 3), mdu*((n + 2) / 3) );
        // }
        // cout << ans + min( n*((m + 2) / 3), m*((n + 2) / 3) ) 
        // << endl;
    }

    
    return 0;
}
