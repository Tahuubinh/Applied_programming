#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;
int t;

const int M = 2e5 + 1;
int n, m, l[M], r[M], x[M];

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> m;
        for (int i = 1; i <= m; ++i){
            cin >> l[i] >> r[i] >> x[i];
        }
    }

    
    return 0;
}
