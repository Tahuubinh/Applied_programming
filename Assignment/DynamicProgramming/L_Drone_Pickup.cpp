#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;

int n, k, maxa;
int a[3001], c[3001];
int total[3001][101];
bool check[3001][101];

int dp(int pos, int step){
    if (check[pos][step]){
        return total[pos][step];
    }
    check[pos][step] = 1;
    int maxtemp = 0;
    for (int i = max(1, pos - maxa); i < pos; ++i){
        if (pos - i > a[i]){
            continue;
        }
        int temp = dp(i, step - 1);
        if (temp > maxtemp){
            maxtemp = temp;
        }
    }
    if (maxtemp){
        total[pos][step] = maxtemp + c[pos];
    }
    return total[pos][step];
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i){
        cin >> c[i];
    }
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    maxa = *max_element(a+1, a+1+n);
    total[1][1] = c[1];
    for (int i = 1; i <= n; ++i){
        check[i][1] = 1;
    }
    int res = 0;
    for (int i = 1; i<=k + 1; ++i){
        res = max(res, dp(n, i));
        //cout << total[n][i];
    }
    if (res){
        cout << res;
    } else {
        cout << -1;
    }
    // cout << total[1][1];
    // cout << endl;
    // for (int i = 1; i <= n; ++i){
    //     for (int j = 1; j <= k + 1; ++j){
    //         cout << dp(i, j);
    //         //cout << total[i][j];
    //     }
    //     cout << endl;
    // }

    
    return 0;
}
