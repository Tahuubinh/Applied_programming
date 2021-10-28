#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;

int n, m, cnt;
int a[10002], b[10002], c[10002];

void Try(int btr){
    if (btr > m){
        ++cnt;
    } else{
        if (cnt == 0){
            for (int i = a[btr]; i <= n; ++i){
                if (!b[i]){
                    b[i] = 1;
                    c[btr] = i;
                    Try(btr + 1);
                    if (cnt == 2){
                        break;
                    }
                    b[i] = 0;
                }
            }
        } else{
            for (int i = 1; i <= n; ++i){
                if (!b[i]){
                    b[i] = 1;
                    c[btr] = i;
                    Try(btr + 1);
                    if (cnt == 2){
                        break;
                    }
                    b[i] = 0;
                }
            }
        }
        
    }
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    int flag = 1;
    for (int i = 1; i <= m; ++i){
        cin >> a[i];
        if (a[i] != n + 1 - i){
            flag = 0;
        }
    }
    if (flag){
        cout << -1;
    } else{
        Try(1);
        for (int i = 1; i <= m; ++i){
            cout << c[i] << ' ';
        }
    }
    int i;
    
    
    
    return 0;
}
