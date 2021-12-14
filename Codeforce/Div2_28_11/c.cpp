#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;
int t;

const int M = 1e6 + 1;
int n, e;
int a[M];

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

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> e;
        for (int i = 1; i <= n; ++i){
            cin >> a[i];
        }
        ll count = 0;
        for (int i = 1; i <= e; ++i){
            //cout << isPrime(a[i]) << ' ';
            // if (a[i] == 1){
            //     int j = i + e;
            //     while (j <= n && a[j] == 1){
            //         j += e;
            //     }
            //     if (j > n || !isPrime(a[j])){
            //         continue;
            //     }
            //     j += e;
            //     ++count;
            //     while (j <= n){
            //         if (a[j] > 1){
            //             break;
            //         }
            //         //cout << i << j <<' ';
            //         j += e;
            //         ++count;
            //     }
                
            //     continue;
            // }
            if (!isPrime(a[i])){
                continue;
            }
            int j = i + e;
            while (j <= n){
                if (a[j] > 1){
                    break;
                }
                //cout << i << j <<' ';
                j += e;
                ++count;
            }
        }
        for (int i = e + 1; i <= n; ++i){
            if (!isPrime(a[i])){
                continue;
            }
            int flag = 0;
            int temp = i - e;
            while (temp > 0 && a[temp] == 1){
                ++flag;
                temp -= e;
            }
            count += flag;
            int j = i + e;
            while (j <= n){
                if (a[j] > 1){
                    break;
                }
                //cout << i << j <<' ';
                j += e;
                ++count;
                count += flag;
            }
        }
        cout << count << endl;
    }

    
    return 0;
}
