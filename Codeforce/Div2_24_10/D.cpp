#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;
int t;

//int a[100002];

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        int temp, sum = 0;
        int a0, a1;
        int n;
        cin >> n;
        cin >> a0;
        cin >> a1;
        if (n == 2){
            cout << -a1 << ' ' << a0 << endl;
            continue;
        }
        for (int i = 2; i < n; ++i){
            cin >> temp;
            sum += temp;
        }
        int sum01 = a0 + a1;
        int sumall = a0 + a1 + sum;
        if (a0 != sumall){
            temp = sum + a1;
            cout << -temp << ' ';
            for (int i = 1; i < n; i++){
                cout << a0 << ' ';
            }
            cout << endl;
            continue;
        }
        if (a1 != sumall){
            temp = sum + a0;
            cout << a1 << ' ';
            cout << -temp << ' ';
            for (int i = 2; i < n; i++){
                cout << a1 << ' ';
            }
            cout << endl;
            continue;
        }
        cout << -sum << ' ' << -sum << ' ';
        for (int i = 2; i < n; i++){
            cout << sum01 << ' ';
        }
        cout << endl;
    }

    
    return 0;
}
