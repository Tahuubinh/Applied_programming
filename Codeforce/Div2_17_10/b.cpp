#include <bits/stdc++.h>
using namespace std;

int t;
int a[100005], b[100005], c[100005], d[100005];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int temp;
        for (int i = 1; i <= n; ++i){
            d[i] = 0;
        }
        for (int i = 1; i <= m; ++i){
            cin >> a[i] >> b[i] >> c[i];
            d[b[i]] = 1;
        }
        for (int i = 1; i <= n; ++i){
            if (d[i] == 0){
                temp = i;
                break;
            }
        }
        for (int i = 1; i <= n; ++i){
            if (i == temp)
                continue;
            cout << temp << ' ' << i << '\n';
        }
    }

    
    return 0;
}
