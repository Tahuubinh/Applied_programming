#include <bits/stdc++.h>

using namespace std;
// To prevent overflow, we should modulo each a, b first

const unsigned int divisor = pow(10, 9) + 7;
long long a[1000001];


int main(){
    int n;
    cin >> n;
    long long sum = 0;

    for (int i = 0; i < n; ++i){
        cin >> a[i];
        a[i] %= divisor;
        sum += a[i];
        sum %= divisor;
    }

    cout << sum;
    return 0;
}
