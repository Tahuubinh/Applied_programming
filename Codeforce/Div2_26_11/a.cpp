#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;
int t;

const int M = 101;
ll a[M];
int n, l, r, k;

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> l >> r >> k;
        for (int i = 0; i < n; ++i){
            cin >> a[i];
        }
        sort(a, a + n);
        // for (int i = 0; i < n; ++i){
        //     cout << a[i] << ' ';
        // }
        ll sum = 0;
        int cnt = 0;
        for (int i = 0; i < n; ++i){
            if (a[i] < l){
                continue;
            }
            if (a[i] > r){
                break;
            }
            sum += a[i];
            if (sum > k){
                break;
            }
            ++cnt;
        }
        cout << cnt << endl;
    }

    
    return 0;
}
