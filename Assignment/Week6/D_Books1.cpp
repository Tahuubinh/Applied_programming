#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;
int n;

int k, m;
ll r, l, mid, temp, cnt, ans;
int p[501], res[501];

ll check(ll mid){
    temp = 0;
    int j = k;
    cnt = 0;
    for (int i = m; i >= 1; --i){
        if (i < j || cnt + p[i] > mid){
            if (cnt > temp){
                temp = cnt;
            }
            --j;
            if (!j){
                break;
            }
            cnt = 0;
        }
        cnt += p[i];
    }
    if (cnt > temp){
        temp = cnt;
    }
    if (!j){
        return 0;
    }
    return temp;
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    while(n--){
        ans = LLONG_MAX;
        r = 0;
        cin >> m >> k;
        for (int i = 1; i <= m; ++i){
            cin >> p[i];
            r += p[i];
            // if (p[i] < l){
            //     l = p[i];
            // }
        }
        l = 1;
        while(l <= r){
            mid = (l + r) >> 1;
            temp = check(mid);
            if (!temp){
                l = mid + 1;
            } else{
                if (ans > temp){
                    ans = temp;
                    r = ans - 1;
                }
                r = mid - 1;
            }
        }
        //cout << ans << 'a' << endl;
        //cout << check(300);
        int j = k;
        cnt = 0;
        res[j] = 0;
        for (int i = m; i >= 1; --i){
            if (i < j || cnt + p[i] > ans){
                --j;
                res[j] = i + 1;
                cnt = 0;
            }
            cnt += p[i];
        }
        j = 1;
        for (int i = 1; i <= m; ++i){
            if (res[j] == i){
                cout << " / ";
                ++j;
            }
            cout << p[i] << ' ';
        }
        cout << endl;
    }

    
    return 0;
}
