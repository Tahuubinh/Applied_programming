#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;
int t;

ll a, b, x;

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        cin >> a >> b >> x;
        if (a == x || b == x){
            cout << "YES" << endl;
            continue;
        }
        while (1){
            if (a < b){
                swap(a, b);
            }
            if (a < x || !b){
                cout << "NO" << endl;
                break;
            }
            if (!((a - x) % b)){
                cout << "YES" << endl;
                break;
            }
            a %= b;
        }
    }
    
    
    return 0;
}
