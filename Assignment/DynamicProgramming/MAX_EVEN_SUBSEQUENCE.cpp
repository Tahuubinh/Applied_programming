#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;

const int M = 1e6 + 1;
ll a[M];
ll even[M], odd[M];
int n;

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        even[i] = INT_MIN; // odd[i] = 0 mean not reaching the first odd number
    }
    ll ans = LLONG_MIN;
    if (n == 1 && a[1] & 1){
        cout << "NOT_FOUND";
        return 0;
    }
    for (int i = 1; i <= n; ++i){
        if (a[i] & 1){
            odd[i] = max(a[i], a[i] + even[i - 1]);
            if (odd[i - 1]) // If exist one odd number 
                even[i] = a[i] + odd[i - 1];
        }
        else{
            if (odd[i - 1]) // If exist one odd number
                odd[i] = a[i] + odd[i - 1];
            even[i] = max(a[i], a[i] + even[i - 1]);
        }
        if (even[i] > ans){
            ans = even[i];
        }
    }
    cout << ans;
    
    return 0;
}
