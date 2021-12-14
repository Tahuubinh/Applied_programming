#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;
int t;

int n, a, b;

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> a >> b;
        if (a + b > n - 2 || abs(a - b) > 1){
            cout << -1 << endl;
            continue;
        }
        int begin = 1;
        int end = n;
        if (a > b){
            for (int i = 1; i <= a; ++i){
                cout << begin << ' ' << end << ' ';
                ++begin;
                --end;
            }
            for (int i = end; i >= begin; --i){
                cout << i << ' ';
            }
        } else if (a < b){
            for (int i = 1; i <= b; ++i){
                cout << end << ' ' << begin << ' ';
                ++begin;
                --end;
            }
            for (int i = begin; i <= end; ++i){
                cout << i << ' ';
            }
        } else {
            for (int i = 1; i <= a; ++i){
                cout << begin << ' ' << end << ' ';
                ++begin;
                --end;
            }
            for (int i = begin; i <= end; ++i){
                cout << i << ' ';
            }
        }
        cout << endl;
    }

    
    return 0;
}
