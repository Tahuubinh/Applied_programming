#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;
int t;

int n;
string s;

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> s;
        if (s.find("aa") != string::npos){
            cout << 2 << endl;
            continue;
        }
        if (s.find("aba") != string::npos){
            cout << 3 << endl;
            continue;
        }
        if (s.find("aca") != string::npos){
            cout << 3 << endl;
            continue;
        }
        if (s.find("abca") != string::npos){
            cout << 4 << endl;
            continue;
        }
        if (s.find("acba") != string::npos){
            cout << 4 << endl;
            continue;
        }
        if (s.find("abbacca") != string::npos){
            cout << 7 << endl;
            continue;
        }
        if (s.find("accabba") != string::npos){
            cout << 7 << endl;
            continue;
        }
        cout << -1 << endl;
        continue;
    }

    
    return 0;
}
