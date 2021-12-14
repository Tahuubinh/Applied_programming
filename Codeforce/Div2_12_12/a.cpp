#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;
int t;

int n;
int a[101];

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        for (int i = 0; i < n; ++i){
            cin >> a[i];
        }
        if (n == 1){
            cout << a[0] + 1 << endl;
            continue;
        }
        int end = 0;
        for (int i = 1; i < n; ++i){
            if (!a[i] && !a[i - 1]){
                cout << -1 << endl;
                end = 1;
                break;
            }
        }
        if (end){
            continue;
        }
        int height = 1;
        int temp = 0;
        for (int i = 0; i < n; ++i){
            if (a[i]){
                if (!temp){
                    ++height;
                } else {
                    height += 5;
                } 
                temp = 1;
            } else {
                temp = 0;
            }
        }
        cout << height << endl;
    }

    
    return 0;
}
