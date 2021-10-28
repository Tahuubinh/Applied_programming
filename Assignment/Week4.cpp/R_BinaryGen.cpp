#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;

int n;
string s;

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> s;
    char temp = s[0];
    for (int i = n - 1; i >= 0; --i){
        if (s[i] == '1'){
            --s[i];
        } else{
            ++s[i];
            break;
        }
    }
    if (temp == '1' && s[0] == '0'){
        cout << -1;
    } else{
        cout << s;
    }
    

    
    return 0;
}
