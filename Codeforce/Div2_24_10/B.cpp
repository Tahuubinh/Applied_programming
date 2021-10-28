#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;
int t;

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int num0 = 0;
        int num1 = 0;
        int temp;
        for (int i = 0; i < n; ++i){
            cin >> temp;
            if (temp == 0){
                ++num0;
            } else if (temp == 1){
                ++ num1;
            }
        }
        ull ans = 1;
        for (int i = 0; i < num0; ++i){
            ans *= 2;
        }
        cout << ans * num1 << endl;
    }

    
    return 0;
}
