#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;
int t;



int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        int res = 32;
        int a, b;
        cin >> a >> b;
        if (a < b){
            cout << 1;
            continue;
        }
        for (int i = (b == 1? 1: 0); i < 32; ++i){
            int tempa = a, tempres = i;
            int tempb = b + i;
            while (tempa){
                tempa/=tempb;
                ++tempres;
            }
            res = min(res, tempres);
        }
        cout << res << endl;
    }

    
    return 0;
}
