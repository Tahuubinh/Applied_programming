#include <bits/stdc++.h>
using namespace std;

int n;
const int M = 1e5 + 2;
int a[M], amin[M];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> a[i];
    } 
    amin[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; --i){
        amin[i] = min(a[i], amin[i + 1]);
    }
    for (int i = 0; i < n; ++ i){
        double temp = a[i] - 0.5;
        int lindex = lower_bound(amin+i, amin+n, temp) - amin - 1;
        if (lindex - i - 1 < 0){
            cout << -1 << ' ';
            continue;
        }
        cout << lindex - i - 1 << ' ';
    }

    // int a[] = {2, 3, 3, 4, 45, 55};

    // cout << upper_bound(a, a+6, 3) - a;

    
    return 0;
}
