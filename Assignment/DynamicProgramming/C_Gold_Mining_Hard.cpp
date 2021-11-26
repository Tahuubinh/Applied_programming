#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;

int n, L1, L2;
ll a[1000001];
ll b[1000001];
deque<pii> q;
int c;
ll ans, maxb, temp;

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> L1 >> L2;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    b[1] = a[1];
    for (int i = 2; i <= L1; ++i){
        b[i] = a[i];
        // while (!q.empty() && q.back().second < a[i]){
        //     q.pop_back();
        // }
    }
    for (int i = L1 + 1; i <= n; ++i){
        temp = i - L1;
        while (!q.empty() && q.back().second < b[temp]){
            q.pop_back();
        }
        q.push_back(make_pair(temp, b[temp]));
        if (q.front().first < i - L2){
            q.pop_front();
        }
        b[i] = q.front().second + a[i];
    }
    c = max(1, n + 1 - L2);
    for (int i = n; i >= c; --i){
        if (ans < b[i]){
            ans = b[i];
        }
    }
    cout << ans;
    // for (int i = 1; i <= n; ++i){
    //     cout << b[i] << endl;
    // }
    
    return 0;
}
