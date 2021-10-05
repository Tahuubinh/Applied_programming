#include <bits/stdc++.h>

using namespace std;
// To prevent overflow, we should modulo each a, b first

const unsigned int divisor = pow(10, 9) + 7;

unsigned long long a_exp_b_mod(unsigned long long a, unsigned long long b){
    if (b == 0){
        return 1;
    }
    if (b == 1){
        return a % divisor;
    }
    if (b & 1){
        return ((a % divisor) * (a_exp_b_mod(a, b - 1) % divisor)) % divisor;
    }
    else{
        return ((a_exp_b_mod(a, b/2) % divisor) * (a_exp_b_mod(a, b/2) % divisor)) % divisor;
    }
}

int main(){
    unsigned long long a;
    unsigned long long b;
    cin >> a;
    cin >> b;
    cout << a_exp_b_mod(a, b);

    return 0;
}
