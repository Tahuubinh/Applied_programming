#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;

int n,m,i,j,c, minprice = INT_MAX, total;
int price[22][22], visited[22];
stack<int> place;

void Try(int k){    
    if (k == n && minprice > total){
        int temp = place.top();
        total += price[temp][1];
        minprice = total;
        total -= price[temp][1];
    }
    for (int i = 2; i <=n, ++i){        
        int temp = place.top();
        if (!visited[i] && !price[temp][i]){
            visited[i] = 1;
            place.push(i);
            total += price[temp][j];

            Try(k + 1);

            visited[i] = 0;
            place.pop();
            total -= price[temp][j];
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    place.push(1);
    for (int ii = 0; ii < m; ++ii){
        cin >> i >> j >> c;
        price[i][j] = c;
    }
    Try(1);

    
    return 0;
}
