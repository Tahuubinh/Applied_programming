#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
#define fr(i,x,y) for(int i = x; i <= y; ++i)
using ll = long long;
using ull = unsigned long long;

const int N = 1e6 + 1;
int n;
string s;
int a[N];
map<int, ll> m;
int minsum, maxsum;

ll cnt(int n){
    return n * (n - 1) / 2;
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s;
    n = s.size();
    fr(i, 1, n){
        if (s[i - 1] == 49){
            a[i] = s[i - 1] - 48;
        }
        else {
            a[i] = s[i - 1] - 49;
        }
    }
    int sum = 0;
    fr(i, 1, n){
        sum += a[i];
        ++m[sum];
        minsum = min(minsum, sum);
        maxsum = max(maxsum, sum);
    }
    ll ans = 0;
    fr (i, minsum, maxsum){
        ans += cnt(m[i]);
    }
    ans += m[0];
    cout << ans;

    
    
    return 0;
}
