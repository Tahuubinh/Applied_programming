#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;

int n;
int a[10002];

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    int i;
    for (i = n; i > 1; --i){
        if (a[i] > a[i - 1]){
            break;
        }
    }
    if (i == 1){
        cout << -1;
    } else{
        int j;
        for (j = i; j <= n; ++j){
            if (a[j] < a[i - 1]){
                break;
            }
        }
        --j;
        swap(a[i - 1], a[j]);

        int l = i, r = n;
        while(l < r){
            swap(a[l], a[r]);
            ++l; --r;
        }

        for (int i = 1; i <= n; ++i){
            cout << a[i] << ' ';
        }
    }
    
    
    return 0;
}
