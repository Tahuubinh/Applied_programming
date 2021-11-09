#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;
int t;

const int M = 2e5 + 2;
int n, a[M];

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        for (int i = 0; i < n; ++i){
            cin >> a[i];
        }
        sort(a, a+n);
        int mina = a[0];
        for (int i = 1; i < n; ++i){
            if (a[i] - a[i - 1] > mina){
                mina = a[i] - a[i - 1];
            }
        }
        cout << mina << endl;
    }

    
    return 0;
}
