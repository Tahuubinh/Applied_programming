#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;
int t;

const int M = 2e5 + 1;
int n;
int a[M + 1];

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        for (int i = 1; i <= n; ++i){
            cin >> a[i];
        }
        int tmax = *max_element(a, a + n);
        int max2 = a[n];
        int ans = 0;
        int cnt = n;
        while (a[cnt] < tmax){
            ++ans;
            while (a[cnt] <= max2){
                --cnt;
            }
            max2 = a[cnt];
        }
        cout << ans << endl;
    }

    
    return 0;
}
