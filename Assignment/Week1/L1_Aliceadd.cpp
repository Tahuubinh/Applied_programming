#include <bits/stdc++.h>

using namespace std;

// One solution is using vector. However, in this problem, a + b can have a maximum of
// 1 excess digit. Therefore we can write a + b = 10 * c + d

int main(){
    unsigned long long a;
    unsigned long long b;
    cin >> a;
    cin >> b;
    // prevent overflow as below
    unsigned long long c = a / 10 + b / 10 + (a%10 + b%10) / 10;
    int d = (a%10 + b%10) % 10;
    // we dont want predigit 0
    if (c == 0){
        cout << d;
    }
    else {
        cout << c << d;
    }


    return 0;
}
