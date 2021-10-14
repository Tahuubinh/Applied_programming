#include <bits/stdc++.h>
using namespace std;

const int M = 102;
int a[M], neg[M], pos[M], zer[M];
int n;
int i1, i2, i3;

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    i1 = 0; i2 = 0; i3 = 0;
    for (int i = 0; i<n; ++i){
        cin >> a[i];
        if (a[i] < 0){
            neg[i1] = a[i];
            ++i1; 
        } else if (a[i] > 0){
            pos[i2] = a[i];
            ++i2;
        } else{
            zer[i3] = a[i];
            ++i3;
        }
    }
    
    cout << 1 << ' ' << neg[0] << '\n';
    if (i2){
        cout << 1 << ' ' << pos[0] << '\n';
        cout << n - 2 << ' ';
        for (int i = 1; i < i1; ++i){
            cout << neg[i] << ' ';
        }
        for (int i = 1; i < i2; ++i){
            cout << pos[i] << ' ';
        }
        for (int i = 0; i < i3; ++i){
            cout << zer[i] << ' ';
        }
    } else{
        cout << 2 << ' ' << neg[1] << ' ' << neg[2] << '\n';
        cout << n - 3 << ' ';
        for (int i = 3; i < i1; ++i){
            cout << neg[i] << ' ';
        }
        for (int i = 0; i < i3; ++i){
            cout << zer[i] << ' ';
        }
    }
    

    
    return 0;
}
