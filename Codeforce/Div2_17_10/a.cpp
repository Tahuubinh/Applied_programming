#include <bits/stdc++.h>
using namespace std;
int t, n, sum, stop;
int a[103], b[103];


bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
  
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

// void Try(int k){
//     if (!stop){
//         if (!isPrime(sum)){
//             stop = 1;
//             cout << k << '\n';
//         } else{
//             int i;
//             for (i = 1; i <= n; ++i){
//                 if (!b[i]){
//                     sum -= a[i];
//                     b[i] = 1;
//                     if (!isPrime(sum)){
//                         continue;
//                     }
//                     sum += a[i];
//                     b[i] = 0;
//                 }
//             }
//             if (i == n + 1){
//                 for (i = 1; i <= n; ++i){
//                     if (!b[i]){
//                         sum -= a[i];
//                         b[i] = 1;
//                         if (!isPrime(sum)){
//                             continue;
//                         }
//                         sum += a[i];
//                         b[i] = 0;
//                     }
//                 }
//             }
//         }
//     }    
// }


int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        stop = 0;
        sum = 0;
        cin >> n;
        for (int i = 1; i <= n; ++i){
            cin >> a[i];
            b[i] = 0;
            sum += a[i];
        }
        if (!isPrime(sum)){
            cout << n << '\n';
            for (int i = 1; i<=n; ++i){
                cout << i << ' ';
            }
            cout << '\n';
        } else {
            for (int i = 1; i <= n; ++i){
                sum -= a[i];
                if (sum % 2){
                    sum += a[i];
                } else {
                    cout << n - 1 << '\n';
                    for (int j= 1; j <= n; ++j){
                        if (j != i){
                            cout << j << ' ';
                        }
                    }
                    cout << '\n';
                    break;
                }
            }
        }
    }

    
    return 0;
}
