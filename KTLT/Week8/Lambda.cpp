#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;



int main(){
    int a = 1, b = 1, c = 1;
    auto m1 = [a, &b, &c] () mutable{
        auto m2 = [a, b, &c]() mutable{
            cout << a << b << c << endl;
            a = 4; b = 4; c = 4;
        };
    a = 3; b = 3; c = 3;
    m2();
    };
    a = 2; b = 2; c = 2;
    m1();
    cout << a << b << c << endl;
    
    return 0;
}
