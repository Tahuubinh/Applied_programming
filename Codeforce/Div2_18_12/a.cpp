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
        int cnt = 0;
        int n = s.size();
        for (int i = 0; i < n; ++i){
            if (s[i] == 'N'){
                ++cnt;
            }
        }
        if (cnt == 1){
            cout << "No" << endl;
        } else {
            cout << "YES" << endl;
        }
    }

    
    return 0;
}
