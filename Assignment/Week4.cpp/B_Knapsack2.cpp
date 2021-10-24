#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;

const int M = 30e6 + 2;
int n, b, temp;
int a[32], c[32];
int maxvalue[2][M]; //only save current obj (Knapsach) and nearest obj
 
 
int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> b;
    for (int i = 1; i <= n; ++i){
        cin >> a[i] >> c[i];
    }
    int past = 0, cur = 1;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= b; ++j){
            maxvalue[cur][j] = maxvalue[past][j];
            if (a[i] <= j){
                temp = maxvalue[past][j - a[i]] + c[i];
                maxvalue[cur][j] = max(temp, maxvalue[cur][j]);
            }
        }
        swap(cur, past);
    }
    cout << maxvalue[past][b];
    
    return 0;
}