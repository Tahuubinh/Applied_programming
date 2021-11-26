#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;
int t;

int n, k;
int a[1001];
string s;

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        cin >> s;
        int cnt = 0;
        k = 0;
        for (int i = 0; i < n; ++i){
            if (s[i] == '0'){
                ++cnt;
            }
        }
        for (int i = 0; i < cnt; ++i){
            if (s[i] == '1'){
                a[k] = i + 1;
                ++k;
            }
        }
        for (int i = cnt; i < n; ++i){
            if (s[i] == '0'){
                a[k] = i + 1;
                ++k;
            }
        }
        if (!k){
            cout << 0 << endl;
            continue;
        }
        cout << 1 << endl;
        cout << k << ' ';
        for (int i = 0; i < k; ++i){
            cout << a[i] << ' ';
        }
        cout << endl;

    }

    
    return 0;
}
