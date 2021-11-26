#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;
int t;

int a1, a2, a3;

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        cin >> a1 >> a2 >> a3;
        int m = (a1 + a2 + a3) % 3;
        if (m){
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }

    
    return 0;
}
