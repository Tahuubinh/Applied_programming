#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;
int t;

int n, h;

int a[20], b[20];

void solution(){
    int temp = 1;
    for (int i = 1; i <= n; ++i){
        if (temp <= h && i == b[temp]){
            cout << 1;
            ++temp;
        }
        else {
            cout << 0;
        }
    }
    cout << endl;
}

void Try(int btr){
    if (btr > h){
        solution();
    } else {
        for (int i = btr + n - h; i > b[btr - 1]; --i){
            b[btr] = i;
            Try(btr + 1);
            b[btr] = 0;
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        memset(b, 0, sizeof b);
        cin >> n >> h;
        b[0] = 0;
        Try(1);
        cout << endl;
    }

    
    return 0;
}
