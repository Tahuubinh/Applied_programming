#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;

const ull M = 1e9 + 7;
ull n, k;
ull C[1001][1001];

ull combin(ull n, ull k){
    for (ull i = 1; i <= n; i++) {
        C[i][0] = 1;
        C[i][i] = 1;
        for(ull j = 1; j < i; j++) {
            C[i][j] = C[i - 1][j] % M + C[i - 1][j - 1] % M;
        }
    }
    return C[n][k]%M;
}
 
int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> k >> n;
    
    cout << combin(n, k);
    
    
    return 0;
}