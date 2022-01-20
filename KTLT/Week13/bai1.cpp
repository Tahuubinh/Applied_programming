#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;

int n;

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    int dau = 1;
    int s = 0;
    int end = n << 1;
    for (int i = 1; i < end; i = i + 2){
        s += dau * i;
        dau = -dau;
    }
    cout << "Answer: " << s;
    
    return 0;
}
