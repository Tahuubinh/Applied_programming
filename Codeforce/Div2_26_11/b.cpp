#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;
int t;

const int M = 2e5 + 1;
int a[M];
pii p[M];
int b[M];
int n;

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        for (int i = 1; i <= n; ++i){
            cin >> a[i];
            p[i].first = a[i];
            p[i].second = i;
        }
        sort(p + 1, p + 1 + n);
        // for (int i = 1; i <= n; ++i){
        //     cout << p[i].first << ' ' << p[i].second << endl;
        // }
        // cout << endl;
        for (int i = n; i >= 1; --i){
            int j = n + 1 - i;
            if (j & 1){
                b[p[i].second] = -(j + 1)/2;
            } else{
                b[p[i].second] = j/2;
            }
        }
        ll time = 0;
        for (int i = 1; i <= n; ++i){
            time += 2LL * abs(b[i]) * a[i];
        }
        cout << time << endl;
        cout << 0 << ' ';
        for (int i = 1; i <= n; ++i){
            cout << b[i] << ' ';
        }
        cout << endl;
    }

    
    return 0;
}
