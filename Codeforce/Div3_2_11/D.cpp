#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;
int t;

const int M = 2e5+2;
int n;
int a[M], b[M], r[M];
string s;

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        for (int i = 0; i < n; ++i){
            cin >> a[i];
        }
        int bcnt = 0;
        int rcnt = 0;
        cin >> s;
        for (int i = 0; i < n; ++i){
            if (s[i] == 'B'){
                b[bcnt] = a[i]; 
                ++bcnt;
            } else{
                r[rcnt] = a[i]; 
                ++rcnt;
            }
        }
        int bcheck = 1;
        int rcheck = n;
        sort(b, b + bcnt);
        sort(r, r + rcnt);
        for (int i = 0; i < bcnt; ++i){
            if (b[i] < bcheck){
                cout << "NO";
                goto label;
                
            }
            ++bcheck;
        }
        for (int i = rcnt - 1; i >= 0; --i){
            if (r[i] > rcheck){
                cout << "NO";
                goto label;
                
            }
            --rcheck;
        }
        //cout << bcnt << b[0] << b[1] << endl;
        cout << "YES";
        label:
            cout << endl;
    }

    
    return 0;
}
