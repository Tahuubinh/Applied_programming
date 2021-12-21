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
        int n = s.size();
        if (n & 1){
            cout << "NO" << endl;
            continue;
        }
        int half = n / 2;
        int c = 1;
        for (int i = 0; i < half; ++i){
            if (s[i] != s[i + half]){
                cout << "NO" << endl;
                c = 0;
                break;
            }
        }
        if (c){
            cout << "YES" << endl;
        }
    }

    
    return 0;
}
