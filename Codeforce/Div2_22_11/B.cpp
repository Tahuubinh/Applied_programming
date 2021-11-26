#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;
int t;

int n, a, b;

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> a >> b;
        int m = n / 2;
        if (a > m + 1){
            cout << - 1 << endl;
            continue;
        }
        if (b < m){
            cout << -1 << endl;
            continue;
        }
        if (a < b && b <= m){
            cout << -1 << endl;
            continue;
        }
        if (a < b && a > m){
            cout << -1 << endl;
            continue;
        }
        int save = n;
        cout << a << ' ';
        for (int i = 1; i < m; ++i){
            while (save == b){
                --save;
            }
            cout << save << ' ';
            --save;
        }
        save = 1;
        cout << b << ' ';
        for (int i = 1; i < m; ++i){
            while (save == a){
                ++save;
            }
            cout << save << ' ';
            ++save;
        }
        cout << endl;
    }
    

    
    return 0;
}
