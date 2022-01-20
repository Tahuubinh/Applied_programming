#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
#define fr(i,x,y) for(int i = x; i <= y; ++i)
using ll = long long;
using ull = unsigned long long;

void decToBit(int n){
    stack<int> s;
    cout << n << " -> ";
    while (n){
        s.push(n % 2);
        n /= 2;
    }
    while (!s.empty()){
        cout << s.top();
        s.pop();
    }
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    decToBit(15);
    cout << endl;
    decToBit(12);
    
    
    return 0;
}
