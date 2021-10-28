#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;

int n, m;
int a[10002];

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i){
        cin >> a[i];
    }   
    int i;
    if (a[m] < n){
        ++ a[m];
        goto label;
    }
    for (i = m - 1; i > 0; i--){
        if (a[i] + 1 < a[i + 1]){
            ++a[i];
            break;
        }
    }
    if (i){
        for (int j = i + 1; j <= m; ++j){
            a[j] = a[i] + j - i;
        }
        
        goto label;
    }
    cout << -1;
    return 0;
    label:
        for (int i = 1; i <= m; ++i){
            cout << a[i] << ' ';
        }

    
    return 0;
}
