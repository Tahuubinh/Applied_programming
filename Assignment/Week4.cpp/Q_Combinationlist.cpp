#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;
 
int n, m, k, cnt;
int a[10002];
 
void Try(int btr){
    if (btr > m){
        ++cnt;
    } else{
        for (int i = a[btr - 1] + 1; i <= n - m + btr; ++i){
            a[btr] = i;
            Try(btr + 1);
            if (k == cnt){
                break;
            }
        }
    }
}
 
int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    Try(1);
    if (k == cnt){
        for (int i = 1; i <= m; ++i){
            cout << a[i] << ' ';
        }
    } else{
        cout << -1;
    }
    
    
    return 0;
}