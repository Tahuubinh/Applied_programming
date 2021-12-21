#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;
int t;

const int N = 1e5 + 1;
int n;
int a[N], visited[N];

bool check(int a, int i){
    if (a == i){
        return true;
    }
    if (a & 1){
        if (i > a/2){
            return false;
        }
    } else{
        if (i >= a/2){
            return false;
        }
    }
    return true;
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        memset(visited, 0, sizeof visited);
        cin >> n;
        for (int i = 1 ; i <= n; ++i){
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        int ans = 0;
        int i = 1;
        // if (a[1] == 1){
        //     ans = 0;
        // } else if (a[1] > 2) {
        //     ans = 1;
        // } else {
        //     cout << -1 << endl;
        //     continue;
        // }
        int j = 1;
        for (i = 1; i <= n; ++i){
            while (a[j] <= n && !visited[a[j]] && j <= n){
                visited[a[j]] = 1;
                ++j;
            }
            if (visited[i]){
                continue;
            }
            if (!check(a[j], i)){
                break;
            }
            if (a[j] != i){
                ++ans;
            }
            ++j;
        }
        if (i > n){
            cout << ans << endl;
        } else {
            cout << -1 << endl;
        }
    }

    
    return 0;
}
