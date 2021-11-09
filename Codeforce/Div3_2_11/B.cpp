#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;
int t;

ll x0, n;

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        cin >> x0 >> n;
        int nmod = n % 4;
        if (x0 & 1){
            switch(nmod){
                case 0:
                    cout << x0 << endl;
                    break;
                case 1:
                    cout << x0 + n << endl;
                    break;
                case 2:
                    cout << x0 - 1 << endl;
                    break;
                case 3:
                    cout << x0 - 1 - n<< endl;
                    break;
            }
        } else {
            switch(nmod){
                case 0:
                    cout << x0 << endl;
                    break;
                case 1:
                    cout << x0 - n << endl;
                    break;
                case 2:
                    cout << x0 + 1 << endl;
                    break;
                case 3:
                    cout << x0 + 1 + n<< endl;
                    break;
            }
        }

    }

    
    return 0;
}
