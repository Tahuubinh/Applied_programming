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
        int n;
        cin >> n;
        double a = pow(n, 1.0/2);
        double b = pow(999999999, 1.0/3);
        double c = pow(n, 1.0/6);
        cout << (int)a << ' ' << b << ' ' << (int)c << endl;
        //cout << (int)a + (int)b - (int)c << endl;
    }

    
    return 0;
}
