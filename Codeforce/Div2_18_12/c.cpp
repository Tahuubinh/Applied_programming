#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;
int t;

int k, n;
ll x;
string s;
ll aster[2001], tich[2001], ans[2001];

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> k >> x;
        cin >> s;
        int index = s.find('*');
        if (index < 0){
            cout << s << endl;
            continue;
        }
        ll tcnt = 1;
        int icnt = 0;
        //cout << index;
        for (int i = index; i < n; ++i){
            if (s[i] == 'a' && tcnt > 1){
                aster[icnt] = tcnt;
                ++icnt;
                tcnt = 1;
            } else {
                tcnt += k;
            }
        }
        if (s[n - 1] == '*'){
            aster[icnt] = tcnt;
            ++icnt;
        }
        //cout << icnt;
        int tpos;
        tich[icnt - 1] = 1;

        // for (int i = icnt - 1; i >= 0; --i){
        //     tich *= aster[i];
        //     if (x <= tich){
        //         tpos = i;
        //         break;
        //     }
        // }
        // tich /= aster[tpos];      
        // cout << tpos;

        int indexa = s.find('a');
        if (indexa >= 0){
            --x;
        }
        for (int i = icnt - 2; i >= 0; --i){
            tich[i] = tich[i + 1] * aster[i + 1];
        }

        // for (int i = 0; i < icnt; ++i){
        //     cout << 'a' << aster[i];  
        // }
        // cout << endl;
        // for (int i = 0; i < icnt; ++i){         
        //     cout << tich[i] << ' ';
        // }
        // cout << endl;

        for (int i = 0; i < icnt; ++i){
            ans[i] = x/tich[i];
            x %= tich[i];
            //cout << ans[i] << ' ';
        }
        int tindex = 0;
        for (int i = 0; i < index; ++i){
            cout << 'a';
        }
        for (int i = index; i < n; ++i){
            if (s[i] == 'a'){
                if (i && s[i - 1] == 'a'){
                    cout << 'a';
                } else {
                    for (int j = 0; j < ans[tindex]; ++j){
                        cout << 'b';
                    }
                    cout << 'a';
                    ++tindex;
                }
            }
        }

        if (s[n - 1] == '*'){
            for (int i = 0; i < ans[icnt - 1]; ++i){
                cout << 'b';
            }
        }

        cout << endl;
    }

    
    return 0;
}
