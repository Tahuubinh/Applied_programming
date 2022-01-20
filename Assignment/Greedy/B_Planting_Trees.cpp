#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
#define fr(i,x,y) for(int i = x; i <= y; ++i)
using ll = long long;
using ull = unsigned long long;

const int N = 100001;
int n;
int a[N];

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    fr(i, 1, n){
        cin >> a[i];
    }
    sort (a + 1, a + n + 1);
    int j = 2;
    for (int i = n; i > 0; --i){
        a[i] += j;
        ++j;
    }
    cout << *max_element(a + 1, a + 1 + n);
    
    
    return 0;
}
