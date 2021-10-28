#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;

int c[25][25], visited[12], place[12];
int n, res = INT_MAX, cost, temp;


void Try(int k){
    if (k > n){
        temp = place[k - 1];
        cost += c[temp][0];
        if (cost < res){
            res = cost;
        }
        cost -= c[temp][0];
    } else{
        for (int i = 1; i <= n; ++i){
            if (!visited[i]){
                temp = place[k - 1];
                cost += c[temp][i] + c[i][i + n];
                if (cost >= res){
                    cost -= (c[temp][i] + c[i][i + n]);
                    continue;
                }
                place[k] = i + n;
                visited[i] = 1;
                //cout << i << 'k' << k << endl;
                Try(k + 1);
                visited[i] = 0;
                temp = place[k - 1];
                //cout << i << '-' << visited[i]<< '-' << k << endl;
                cost -= (c[temp][i] + c[i][i + n]);
            }
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n;
    for (int i = 0; i<=2*n; ++i){
        for (int j = 0; j <= 2*n; ++j){
            cin >> c[i][j];
        }
    }
    Try(1);
    cout << res;

    
    return 0;
}
