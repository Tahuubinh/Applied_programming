#include <bits/stdc++.h>
using namespace std;

int t, a, b, c;

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--){
        cin >> a >> b >> c;
        int d = a;
        d = max(d, b);
        d = max(d, c);
        a = d - a;
        b = d - b;
        c = d - c;
        if ( (a==0) + (b==0) + (c==0) > 1){
            cout << a + 1 << ' ' << b + 1 << ' '
                 << c + 1 << ' ';
        } else {
            cout << ((a==0)?0:a+1) << ' '
                << ((b==0)?0:b+1) << ' '
                << ((c==0)?0:c+1) << ' ';
        }
        cout << '\n';
        
    }

    
    return 0;
}
