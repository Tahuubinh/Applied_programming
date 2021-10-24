#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;

const int N = 17, M = 5;
int n, m, n_index, ans = INT_MAX, temp;
int c[N], a[N][N], inturn[N], belong[N], credit[M], turn[N];

bool check(int k){
    for (int i = 1; i <= n; ++i){
        if (a[i][k]){
            if (!inturn[i]){
                return false;
            }
        }
    }
    return true;
}

void Try(int k){
    if (k > n){
        int tempmax = credit[1];
        for (int i = 2; i <= n; ++i){
            if (credit[i] > tempmax){
                tempmax = credit[i];
            }
        }
        if (tempmax < ans){
            ans = tempmax;
        }
    } else{
        for (int i = 1; i <= m; ++i){
            //cout << credit[i];
            credit[i] += c[turn[k]];
            if (credit[i] >= ans){
                credit[i] -=c[turn[k]];
                continue;
            }
            belong[turn[k]] = 1;
            Try(k + 1);
            credit[i] -=c[turn[k]];
            belong[turn[k]] = 0;
        }
    }
    
}

int main(){
    //ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        cin >> c[i];
    }
    for (int i = 1; i <=n; ++i){
        for (int j = 1; j <=n; ++j){
            cin >> a[i][j];
        }
    }
    n_index = 1;
    temp = 1;
    while(temp <=n){
        while (inturn[n_index] || !check(n_index)){
            n_index = (n_index + 1) % n;
            if (!n_index)
                n_index = n;
        }
        turn[temp] = n_index;
        inturn[n_index] = 1;
        ++temp;
    }
    // for (int i = 1; i <= n; ++i){
    //     cout << turn[i];
    // }
    Try(1);
    cout << ans;

    return 0;
}
