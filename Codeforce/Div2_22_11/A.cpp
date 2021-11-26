#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;
int t;

int x, y;

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        cin >> x >> y;
        if ((x ^ y) & 1){
            cout << "-1 -1" << endl;
            continue;
        }
        if (x & 1){
            if (x < y){
                cout << x << ' ' << (y - x)/2 << endl;
            }
            else{
                cout << (x - y) / 2 << ' ' << y << endl;;
            }
        }
        else{
            cout << x/2 << ' ' << y/2 << endl;
        }
    };

    
    return 0;
}
