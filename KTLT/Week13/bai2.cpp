#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;

int n;

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    int ans = 1;
    for (int i = 2; i <= n; ++i){
        ans *= i;
    }
    cout << "Answer: " << ans;
    
    return 0;
}
