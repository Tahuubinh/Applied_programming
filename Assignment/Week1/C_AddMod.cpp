#include <bits/stdc++.h>

using namespace std;
// To prevent overflow, we should modulo each a, b first

unsigned int divisor = pow(10, 9) + 7;

int main(){
    unsigned long long a;
    unsigned long long b;
    cin >> a;
    cin >> b;
    unsigned long long result = (a % divisor + b % divisor) % divisor;
    cout << result;

    return 0;
}
