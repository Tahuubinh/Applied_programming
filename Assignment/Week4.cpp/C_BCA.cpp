#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;

const int M = 12, N = 32;
int m, n, k, temp, temp2, ans = INT_MAX;
int a[M][N], teacher[M];
vector<int> b[N];

bool check(int i, int k){
    for (int v: b[k]){
        if (a[i][v] == 2){
            return false;
        }
    }
    return true;
}

void Try(int k){
    if (k > n){
        int tempmax = teacher[1];
        for (int i = 2; i <= m; ++i){
            if (teacher[i] > tempmax){
                tempmax = teacher[i];
            }
        }
        if (tempmax < ans){
            ans = tempmax;
        }
    }
    for (int i = 1; i <=m; ++i){
        if (!a[i][k]){
            continue;
        }
        if (check(i, k)){
            ++teacher[i];
            if(teacher[i] >= ans){
                --teacher[i];
                continue;
            }            
            a[i][k] = 2;
            Try(k + 1);
            a[i][k] = 1;
            --teacher[i];
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> m >> n;
    for (int i = 1; i <= m; ++i){
        cin >> k;
        for (int j = 1; j <= k; ++j){
            cin >> temp;
            a[i][temp] = 1;
        }
    }
    cin >> k;
    for (int i = 0; i < k; ++i){
        cin >> temp >> temp2;
        b[temp].push_back(temp2);
        b[temp2].push_back(temp);
    }
    Try(1);
    if (ans == INT_MAX){
        cout << -1;
    } else
        cout << ans;
    
    return 0;
}
