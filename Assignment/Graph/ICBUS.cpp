#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
#define fr(i,x,y) for (int i = x; i <= y; ++i)
using ll = long long;
using ull = unsigned long long;

const int N = 5e3 + 1;
int n, k;
int c[N], d[N];

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;

    fr(i, 1, n){
        cin >> c[i];
        cin >> d[i];
    }
    fr(i, 1, n){
        cout << c[i] << ' ' << d[i];
        cout << endl;
    }
    // for (int i = 1; i <= k; ++i){

    // }
    
    
    return 0;
}
