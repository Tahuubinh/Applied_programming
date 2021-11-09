#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;
int t;

string sfull, s;
char c[150];
int absc(char a, char b){
    if (c[a] < c[b]){
        return c[b] - c[a];
    }
    return c[a] - c[b];
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        cin >> sfull;
        for (int i = 0; i < 26; ++i){
            c[sfull[i]] = i;
        }
        cin >> s;
        int ans = 0;
        int len = s.size() - 1;
        for (int i = 0; i < len; ++i){
            ans += absc(s[i], s[i + 1]);
        }
        cout << ans << endl;
    }

    
    return 0;
}
