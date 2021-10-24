#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;
 
int n, b;
int a[32], c[32];
//unordered_map<int, int> check[32]; // if maxvalue == 0 then obj > weight
unordered_map<int, int> m[32]; // m[i][n] is max value from objects between 1 to i that have max weight n
 
int maxvalue(int obj, int weight){
    if (obj == 1){
        if (a[obj] > weight){
            return 0;
        } else{
            return c[obj];
        }
    }
    if (m[obj][weight]){
        return m[obj][weight];
    }
    int haveobj = 0;
    if (a[obj] <= weight){
        haveobj = c[obj] + maxvalue(obj - 1, weight - a[obj]);
    }
    int notobj = maxvalue(obj - 1, weight);
    m[obj][weight] = max(haveobj, notobj);
    return m[obj][weight];
}
 
 
 
int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> b;
    for (int i = 1; i <= n; ++i){
        cin >> a[i] >> c[i];
    }
    cout << maxvalue(n, b);
    
    return 0;
}