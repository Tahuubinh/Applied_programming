#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
#define fr(i,x,y) for(int i = x; i <= y; ++i)
using ll = long long;
using ull = unsigned long long;

const ll money[] = {1000, 2000, 3000, 5000};
ll w, c;
ll num[16][4];
ll pow_10[16];
int t;

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    pow_10[0] = 1;
    fr(i, 1, 15){
        pow_10[i] = pow_10[i - 1] * 10;
    }
    cin >> t;
    while (t--){
        cin >> w >> c;
        if (w % 1000){
            cout << 0 << endl;
            continue;
        }
        ll minout = 0;
        ll C = c;
        while(w && C >= 0){
            for (int i = 3; i >= 0; --i){
                num[C][i] = w / (money[i] * pow_10[C]);
                minout += num[C][i];
                w -= money[i] * pow_10[C] * num[C][i];
            }
            --C;
        }
        ll s = 1;
        fr(i, 0, c){
            ll cb_4000 = min(num[i][0], num[i][2]);
            ll cb_8000 = min(num[i][0], num[i][3]);
            s *= (cb_4000 + cb_8000 + 1);
        }
        cout << minout << " " << s << endl;
        fr(i, 0, c){
            fr(j, 0, 3){
                num[i][j] = 0;
            }
        }
    }
    
    
    return 0;
}
