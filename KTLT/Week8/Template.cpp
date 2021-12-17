#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;
template<typename C>
C maxval(C x, C y){
    return (x > y) ? x:y;
}

template<typename C>
C minval(C x, C y){
    return (x < y) ? x:y;
}


int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int i = maxval(3, 7);
    cout << i << endl;
    cout << minval(3, 7) << endl;
    double d = maxval (5.6, 6.3);
    cout << d << endl;
    cout << minval(5.6, 6.3);
    return 0;
}
