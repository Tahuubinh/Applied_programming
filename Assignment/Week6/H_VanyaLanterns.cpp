#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;

int n, l;
int a[1001];

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> l;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    sort (a + 1, a + 1 + n);
    int d = max(a[1], l - a[n]) * 2; // head and tail of the street
    for (int i = 2; i <= n; ++i){
        d = max(d, a[i] - a[i - 1]);
    }
    printf("%f",d/2.0);
    
    return 0;
}
