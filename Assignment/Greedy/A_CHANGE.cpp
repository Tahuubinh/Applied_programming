#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
#define fr(i,x,y) for(int i = x; i <= y; ++i)
using ll = long long;
using ull = unsigned long long;

int n;
int x[6] = {1, 5, 10, 50, 100, 500};
int cnt = 0;

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    n = 1000 - n;
    int r = 5;
    int ans = n;
    while (ans){
        cnt += ans / x[r];
        ans %= x[r];
        --r;
    }

    cout << cnt;
    
    
    return 0;
}
