#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;

int n, k, m, temp1, temp2, cnt;
int a[31][31], b[31], c[31];

void Try(int btr){
    if (btr > k + 1){
        ++cnt;
    } else{
        for (int i = 1; i <= n; ++i){
            if (btr == 1){
                b[i] = 1;
                c[btr] = i;
                Try(btr + 1);
                b[i] = 0;
                continue;
            }
            if (a[c[btr - 1]][i] && !b[i]){
                b[i] = 1;
                c[btr] = i;
                Try(btr + 1);
                b[i] = 0;
            }
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    cin >> m;
    for (int i = 1; i <= m; ++i){
        cin >> temp1 >> temp2;
        a[temp1][temp2] = a[temp2][temp1] = 1;
    }
    Try(1);
    cout << cnt/2;
    
    return 0;
}
