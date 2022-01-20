#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;

int n;

void iter_binary(int m){
    stack<int> stk;
    while(m > 0){
        stk.push(m);
        m /= 2;
    }

    while (!stk.empty()){
        int u = stk.top();
        stk.pop();
        cout << u % 2;
    }
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    cout << "Binary form of " << n << ": ";
    iter_binary(n);
    
    return 0;
}
