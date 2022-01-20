#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int k, t, a;
    cin >> n;
    int ans = 0, sum = 0;
    while(n--){
        cin >> k >> t;
        if (t == 1){
            while(k--){
                cin >> a;
                sum += a;
                ans = max(ans, -sum);
            }
        }
        else if (t == -1){
            while(k--){
                cin >> a;
                sum -= a;
                ans = max(ans, -sum);
            }
        }
        
    }
    cout << ans;
}