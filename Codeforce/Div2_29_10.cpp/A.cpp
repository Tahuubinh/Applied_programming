#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;
int t;
string s;

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        cin >> s;
        int len = s.size();
        if (len < 2){
            cout << s << endl;
            continue;
        }
        if (s[0] == s[len - 1]){
            cout << s << endl;
        } else {
            s[len - 1] = s[0];
            cout << s << endl;
        }
    }

    
    return 0;
}
