#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;

ll n, m, maxh, sum, mid, temp, ans;
ll h[1000001];

ll sumcut(ll cut){
    sum = 0;
    for (int i = 1; i <= n; ++i){
        if (h[i] > cut){
            sum += h[i] - cut;
        }
    }
    return sum;
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        cin >> h[i];
        if (maxh < h[i]){
            maxh = h[i];
        }
    }
    ll low = 0, height = maxh;
    while(low <= height){
        mid = (low + height) >> 1;
        temp = sumcut(mid);
        if (temp == m){
            ans = mid;
            break;
        } else if (temp < m){
            height = mid - 1;
        } else{
            ans = mid;
            low = mid + 1;
        }
    }
    cout << ans;
    return 0;
}
