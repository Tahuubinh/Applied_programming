#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;

int n, k, cnt, first, finish;
int a[10002], b[10002];
int prod = 1;

void Try(int btr){
    if (btr > n){
        ++cnt;
    } else{
        for (int i = 1; i <= n; ++i){
            if (!b[i]){
                a[btr] = i;
                b[i] = 1;
                Try(btr + 1);
                if (k == cnt){
                    break;
                }
                b[i] = 0;
            }
        }
    }
}

void Try2(int btr){
    if (btr > n){
        ++cnt;
    } else{
        for (int i = 1; i <= n; ++i){
            if (!b[i]){
                a[btr] = i;
                b[i] = 1;
                Try2(btr + 1);
                if (finish == cnt){
                    break;
                }
                b[i] = 0;
            }
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    int temp = n;
    if (n <= 12){
        for (int i = 2; i<=n - 1; ++i){
            prod *= i;
        }
        
        //cout << prod << temp;
        if (prod * n < k){
            cout << -1;
        } else{
            first = (k - 1)/prod + 1;
            cout << first << ' ';
            b[first] = 1;
            finish = k - (first - 1)*prod;
            Try2(2);
            for (int i = 2; i <=n; ++i){
                cout << a[i] << ' ';
            }
        }
    } else {
        Try(1);
        if (cnt == k){
            for (int i = 1; i <=n; ++i){
                cout << a[i] << ' ';
            }
        } else{
            cout << -1;
        }
    }
    
    
    return 0;
}
