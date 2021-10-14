#include <bits/stdc++.h>

using namespace std;

int a, b, c;

long long num(int from, int to, int c){
    int f = from;
    int t = 0;
    int temp;
    long long ans = 1; // fill f
    while (f!=c && t!=c){
        if (t == to){
            t = 0;
            ++ans;
        }
        else if (f==0){
            f = from;
            ++ans;
        } else{
            temp = min(f, to - t);
            f -= temp;
            t += temp;
            ++ans;
        }
    }
    return ans;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> a >> b >> c;
    if (c % __gcd(a, b)){
        cout << -1;
    }
    else if (c > a && c>b){
        cout << -1;
    }
    else{
        cout << min(num(a,b,c), num(b,a,c));
    }
    
    return 0;
}
