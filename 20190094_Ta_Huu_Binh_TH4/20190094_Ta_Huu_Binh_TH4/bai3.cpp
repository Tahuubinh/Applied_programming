#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define fr(i,x,y) for(int i = x; i <= y; ++i)
using Vector = tuple<double, double, double>;
using ll = long long;
using ull = unsigned long long;

Vector cross_product(Vector a, Vector b) {
    double x = get<1>(a) * get<2>(b) - get<1>(b) * get<2>(a);
    double y = get<2>(a) * get<0>(b) - get<2>(b) * get<0>(a);
    double z = get<0>(a) * get<1>(b) - get<0>(b) * get<1>(a);
    return {x, y, z};
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << setprecision(2) << fixed;
    Vector a {1.2, 4, -0.5};
    Vector b {1.5, -2, 2.5};
    Vector c = cross_product(a, b);
    cout << get<0>(c) << ' ' << get<1>(c) << ' ' << get<2>(c) << endl;

    
    
    return 0;
}
