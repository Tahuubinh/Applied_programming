#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;
int t;

int a[7];

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        for (int i = 0; i < 7; ++i){
            cin >> a[i];
        }
        sort(a, a+7);
        cout << a[6] - a[5] << ' ' <<
            a[6] - a[4] << ' ' <<
            a[4] + a[5] - a[6] << endl;
    }

    
    return 0;
}
