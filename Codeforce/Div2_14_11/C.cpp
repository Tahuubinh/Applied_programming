#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;
int t;

int n;
int a[101];
int b[101];

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        for (int i = 1; i <= n; ++i){
            cin >> a[i];
        }
        for (int i = 1; i <= n; ++i){
            cin >> b[i];
        }
        sort(a + 1, a + 1 + n);
        sort(b + 1, b + 1 + n);
        int i;
        for (i = 1; i <= n; ++i){
            if (b[i] - a[i] > 1){
                cout << "NO" << endl;
                break;
            }
        }
        if (i > n){
            cout << "Yes" << endl;
        }
    }

    
    return 0;
}
