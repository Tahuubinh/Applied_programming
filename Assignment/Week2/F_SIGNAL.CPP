#include <bits/stdc++.h>

using namespace std;
const int MAX = 2e5 + 2;
int a[MAX], lmax[MAX], rmax[MAX];
int n, b, res;

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> b;
    for (int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i){
        if (i == 0){
            lmax[i] = a[i];
        } else{
            lmax[i] = max(a[i], lmax[i - 1]);
        }
    }
    for (int i = n - 1; i >= 0; --i){
        if (i == n - 1){
            rmax[i] = a[i];
        } else{
            rmax[i] = max(a[i], rmax[i + 1]);
        }
    }
    res = -1;
    for (int i = 1; i <= n-1; ++i){
        if ( (lmax[i-1] - a[i]) >=b && (rmax[i + 1] - a[i]) >=b ){
            res = max(res, lmax[i-1] + rmax[i + 1] - 2 * a[i]);
        }
    }
    cout << res;


    
    return 0;
}
