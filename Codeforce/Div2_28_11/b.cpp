#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;

int n, q, ans;
int pos;
char ask;
string s;

bool check(int i){
    if (s[i] != 'a'){
        return false;
    }
    if (s[i + 1] != 'b'){
        return false;
    }
    if (s[i + 2] != 'c'){
        return false;
    } 
    return true;
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    cin >> s;
    for (int i = 0; i <= n - 3; ++i){
        if (s[i] != 'a'){
            continue;
        }
        if (s[i + 1] != 'b'){
            continue;
        }
        if (s[i + 2] != 'c'){
            continue;
        }
        ++ans;
    }
    for (int i = 0; i < q; ++i){
        cin >> pos >> ask;
        if (s[pos - 1] == ask){
            cout << ans << endl;
            continue;
        }
        ans -= check(pos - 3) + check(pos - 2) 
            + check(pos - 1) + check(pos) + check(pos + 1);
        s[pos - 1] = ask;
        ans += check(pos - 3) + check(pos - 2) 
            + check(pos - 1) + check(pos) + check(pos + 1);
        cout << ans << endl;
    }
    
    
    return 0;
}
