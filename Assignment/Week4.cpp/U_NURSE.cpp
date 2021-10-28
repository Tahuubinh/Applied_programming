#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;

const int M = 1e9 + 7;
int n, k1, k2, cnt1, cnt, flag = 1;
int a[1002];

bool check(int i){
    if (i){
        return (cnt1 < k2);
    }
    return (cnt1 >= k1);
}

void Try(int btr){
    if (btr > n){
        // for (int i = 1; i <= n; i++){
        //     cout << a[i] << ' ';
        // }
        // cout << endl;
        if (!a[n] || cnt1 >= k1){
            
            ++cnt;
        }
        if (cnt >= M){
            cnt -= M;
        }
    } else{
        for (int i = 0; i < 2; ++i){
            if (btr == 1){
                a[btr] = i;
                int temp = cnt1;
                if (i){
                    ++cnt1;
                } else{
                    cnt1 = 0;
                }
                //cout << btr << i << ' ' << cnt1 << endl;
                Try(btr + 1);
                if (i){
                    --cnt1;
                } else{
                    cnt1 = temp;
                }
                continue;
            }
            if (check(i)){
                a[btr] = i;
                int temp = cnt1;
                if (i){
                    ++cnt1;
                } else{
                    cnt1 = 0;
                }
                //cout << btr << i << ' ' << cnt1 << endl;
                Try(btr + 1);
                if (i){
                    --cnt1;
                } else{
                    cnt1 = temp;
                }
            }
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n >> k1 >> k2;
    
    Try(1);
    cout << cnt;
    
    return 0;
}
