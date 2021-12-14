#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;
int t;

int n;
int a[16];

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        ll prod = 1;
        for (int i =1; i <= n; ++i){
            cin >> a[i];
            while (a[i] %2 ==0){
                a[i] = a[i] / 2;
                prod = prod * 2;
            }
        }
        //cout << (a[1] & 1 == 0);
        // for (int i =1; i <= n; ++i){
        //     while (a[i] & 1 == 0){
        //         a[i] = a[i] / 2;
        //         prod = prod * 2;
        //     }
        //     cout << a[i] << ' ';
        // } 
        // cout << prod << endl;
        int maxa = a[1];
        ll sum = 0;
        for (int i =1; i <= n; ++i){
            if (a[i] > maxa){
                maxa = a[i];
            }
            sum += a[i];
        } 
        sum -= maxa;
        sum += maxa * prod;
        cout << sum << endl;
    }

    
    return 0;
}
