#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;
int t;

ll n, k;

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> k;
        ll i = 0;
        ll prod = 1;
        while (prod < n && prod <= k){
            ++i;
            prod *= 2;
        }
        //cout << prod;
        if (prod >= n){
            cout << i << endl;
            continue;
        }
        n = (n - prod - 1)/k + 1;
        cout << n + i << endl;
    }

    
    return 0;
}
