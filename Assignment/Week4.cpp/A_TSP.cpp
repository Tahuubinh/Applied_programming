#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;

int n,m,i,j,c, minprice = INT_MAX, total;
int price[22][22], visited[22], place[22];

void Try(int k){  
    int temp = place[k];
    if (k == n && price[temp][1]){
        total += price[temp][1];
        if (minprice > total)
            minprice = total;
        total -= price[temp][1];
    } else{
        for (int ii = 2; ii <=n; ++ii){     
            if (!visited[ii] && price[temp][ii]){
                total += price[temp][ii];
                if (total >= minprice){
                    total -= price[temp][ii];
                    continue;
                }
                visited[ii] = 1;
                place[k + 1] = ii;
                Try(k + 1);
                visited[ii] = 0;
                total -= price[temp][ii];
            }
        }
    }

}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    place[1] = 1;
    for (int ii = 0; ii < m; ++ii){
        cin >> i >> j >> c;
        price[i][j] = c;
    }
    Try(1);
    if (n == 1){
        cout << 0;
    } else
        cout << minprice;

    
    return 0;
}
