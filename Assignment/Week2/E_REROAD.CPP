#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e5 + 2;
int a[MAX];
int n, q, p, c, res;

int begin(int i){
    if (i == 1){
        return 1;
    }
    return (a[i] != a[i - 1]);
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i]; // type of tar
    }
    cin >> q;

    res = 1;
    for (int i = 2; i <= n; ++i){
        res += begin(i);
    }
    
    while(q--){
        cin >> p >> c;
        if (p == n){
            res -= begin(n);
            a[n] = c;
            res += begin(n);
        } else{
            res -= begin(p) + begin(p + 1);
            a[p] = c;
            res += begin(p) + begin(p + 1);
        }
        cout << res << '\n';
        
    }
    

    
    return 0;
}
