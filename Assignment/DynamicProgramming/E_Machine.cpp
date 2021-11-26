#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;

const int M = 2e6 + 1;
int n, maxs;
int s[M], t[M], maxl[M];

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> s[i] >> t[i];
        maxl[t[i]] = max(maxl[t[i]], t[i] - s[i]);
    }
    maxs = *max_element(s, s + n);
    for (int i = 1; i <= maxs; ++i){
        maxl[i] = max(maxl[i], maxl[i - 1]);
    }
    int ans = -1;
    for (int i = 1; i <= n; ++i){
        if (maxl[s[i] - 1]){
            ans = max(ans, t[i] - s[i] + maxl[s[i] - 1]);
        }
    }
    cout << ans;
    return 0;
}
