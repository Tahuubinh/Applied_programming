#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;
int t;

int n, c;
int a[100001];
int l, r, temp, cnt, mid, ans;

bool check(int mid){
    temp = a[1];
    cnt = c - 1;
    for (int i = 2; i <= n; ++i){
        if (a[i] - temp >= mid){
            temp = a[i];
            --cnt;
            if (!cnt){
                break;
            }
        }
    }
    if (cnt){
        return false;
    }
    return true;
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> c;
        for (int i = 1; i <= n; ++i){
            cin >> a[i];
        }
        sort(a + 1, a+1+n);
        l = 1;
        r = 1e9 + 2;
        while (l <= r){
            mid = (l + r) >> 1;
            temp = check(mid);
            if (temp){
                ans = mid;
                l = mid + 1;
            } else{
                r = mid - 1;
            }
        }
        cout << ans << endl;
    }
    

    
    return 0;
}
