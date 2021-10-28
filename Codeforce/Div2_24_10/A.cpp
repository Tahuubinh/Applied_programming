#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;
int t;



int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        int a, b, c;
        cin >> a >> b >> c;
        if ((a + 2*b + 3*c)%2){
            cout << 1 << endl;
        }else{
            cout << 0 << endl;
        }
    }

    
    return 0;
}
