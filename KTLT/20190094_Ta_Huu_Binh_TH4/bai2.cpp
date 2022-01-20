#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define fr(i,x,y) for(int i = x; i <= y; ++i)
using Point = pair<double, double>;
using ll = long long;
using ull = unsigned long long;

double area(Point a, Point b, Point c){
    double ab = sqrt((a.first - b.first)*(a.first - b.first) +
                    (a.second - b.second)*(a.second - b.second));
    double bc = sqrt((b.first - c.first)*(b.first - c.first) +
                    (b.second - c.second)*(b.second - c.second));
    double ca = sqrt((c.first - a.first)*(c.first - a.first) +
                    (c.second - a.second)*(c.second - a.second));
    double p = (ab + bc + ca) / 2;
    return sqrt(p * (p - ab) * (p - bc) * (p - ca));
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << setprecision(2) << fixed;
    cout << area({1, 2}, {2.5, 10}, {15, -5.25}) << endl;
    
    
    return 0;
}
