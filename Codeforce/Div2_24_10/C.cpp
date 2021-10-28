#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;
int t;

string s;
int subans(int l, int r, string s, unordered_map<string, int> &b, unordered_map<string, int> &val){
    if (l == r){
        return 1;
    }
    if (l > r){
        return 0;
    }
    string keyb = to_string(l)+'|'+to_string(r);
    if (b[keyb]){
        return val[keyb];
    }
    if (s[r] == s[l]){
        b[keyb] = 1;
        val[keyb] = 2 + subans(l + 1, r - 1, s, b, val);
        return val[keyb];
    } 
    b[keyb] = 1;
    val[keyb] = max(subans(l + 1, r, s, b, val), subans(l, r - 1, s, b, val));
    return val[keyb];

}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        int n;
        cin >> n >> s;
        unordered_map<string, int> val;
        unordered_map<string, int> b;
        cout << n - subans(0, n - 1, s, b, val) << endl;
        
    }

    
    return 0;
}
