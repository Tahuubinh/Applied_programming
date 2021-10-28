#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;

int a[8], b[11];     // i, c, t, h, u, s, k
int n, cnt;

int sum(){
    return a[0]*100 + a[1]*10 + a[2]*2 + a[3]*1000 +
            a[4]*100 + a[5]*10 - a[6]*100 - 62;
}

void Try(int k){
    if (k == 7){
        //cout << k;
        if (sum() == n){
            ++cnt;
        }
    } else {
        for (int i = 1; i < 10; ++i){
            //cout << k;
            if (b[i])
                continue;
            b[i] = 1;
            a[k] = i;
            Try(k + 1);
            b[i] = 0;
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n;
    Try(0);
    cout << cnt;
    return 0;
}
