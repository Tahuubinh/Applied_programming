#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;
int t;

int n;
string s[100];

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        for (int i = 1; i <= n - 2; ++i){
            cin >> s[i];
        }
        string ans = s[1];
        int check = 0;
        for (int i = 2; i <= n - 2; ++i){
            if (s[i - 1][1] != s[i][0]){
                ans += s[i][0];
                check = 1;
            }
            ans += s[i][1];
        }
        if (!check){
            ans += s[n - 2][1];
        }
        cout << ans << endl;
    }

    
    return 0;
}
