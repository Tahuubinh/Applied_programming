#include <bits/stdc++.h>
using namespace std;

int t;
int a[500000];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < k; ++i){
            cin >> a[i];
        }
        sort(a, a + k);
        int sum = 0;
        int i;
        for (i = k - 1; i >= 0; --i){
            sum += n - a[i];
            //cerr << sum << ' ';
            if (sum>= n){
                break;
            }
        }
        //cout << k << i << ' ';
        cout << k - i - 1 << '\n';
    }


    
    return 0;
}
