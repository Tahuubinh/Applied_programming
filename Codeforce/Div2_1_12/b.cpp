#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;
int t;

const int M = 2e5 + 1;
int n;
int a[M];

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        for (int i = 0; i < n; ++i){
            cin >> a[i];
        }
        sort(a, a+n);
        for (int i = 1; i <= n/2; ++i){
            cout << a[i] << ' ' << a[0] << endl;
        }
        // cout << *max_element(a, a + n) << ' ' << 
        //         *min_element(a, a + n) <<endl;
    }

    
    return 0;
}
