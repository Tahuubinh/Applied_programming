#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;

int n, m, cnt, a[13], b[13], sum[25], sub[25], temp1, temp2;
int holes[13][13];

bool check(int m, int n){
    if (holes[m][n]){
        return false;
    }
    if (b[n]){
        return false;
    }
    if (sum[m + n]){
        return false;
    }
    if (sub[m - n + 12]){
        return false;
    }
    return true;
}

void Try(int btr){
    if (btr > n){
        ++cnt;
    } else{
        for (int i = 1; i <= n; ++i){
            if (check(btr, i)){
                a[btr] = i;
                b[i] = 1;
                sum[btr + i] = 1;
                sub[btr - i + 12] = 1;
                Try(btr + 1);
                b[i] = 0;
                sum[btr + i] = 0;
                sub[btr - i + 12] = 0;
            }
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    while (true){
        cin >> n >> m;
        if (n==0 && m==0){
            break;
        }
        cnt = 0;
        memset(b, 0, sizeof b);
        memset(sum, 0, sizeof sum);
        memset(sub, 0, sizeof sub);
        for (int i = 1; i <= n; ++i){
            for (int j = 1; j <= n; ++j){
                holes[i][j] = 0;
            }
        }
        for (int i = 1; i <= m; ++i){
            cin >> temp1 >> temp2;
            holes[temp1][temp2] = 1;
        }

        Try(1);
        cout << cnt << endl;
    }
    
    return 0;
}
