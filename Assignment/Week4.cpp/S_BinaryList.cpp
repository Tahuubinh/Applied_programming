#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;

int n, k, i, cnt, cnt0;
int a[10002];
int b[32];

int pow2(int k){
    if (k == 0){
        return 1;
    }
    if (b[k]){
        return b[k];
    }
    if (k & 1){
        b[k] = 2*pow2(k/2)*pow2(k/2);
        return b[k];
    }
    b[k] = pow2(k/2) * pow2(k/2);
    return b[k];
}

void Try(int btr){
    if (btr > n){
        ++cnt;
    } else {
        for (int j = 0; j <=1; ++j){
            if (j){
                a[btr] = 1;
                cnt0 = 0;
                Try(btr + 1);
                if (cnt == k){
                    break;
                }
                continue;
            }
            if (cnt0 < i - 1){
                a[btr] = 0;
                ++cnt0;
                Try(btr + 1);
                if (cnt == k){
                    break;
                }
            }
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k >> i;
    if (n < 31){
        if (pow2(n) < k){
            cout << -1;
            return 0;
        }
    }
    Try(1);
    if (cnt == k){
        for (int j = 1; j <= n; ++j){
            cout << a[j] << ' ';
        }
    } else{
        cout << -1;
    }
    
    

    
    return 0;
}
