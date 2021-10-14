#include <bits/stdc++.h>
using namespace std;

int temp;
int t; 
int res[5];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    cout << t;
    while(t--){
        int n;
        cin >> n;
        for (int j = 0; j < 5; ++j){
            res[j] = 0;
        } 
        
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < 5; ++j){
                cin >> temp;
                res[j] += temp;
            }
        }
        int count = 0;
        for (int i = 0; i < 5; ++i){
            if (res[i] >= n/2){
                ++count;
                if (count == 2){
                    break;
                }
            } 
        }
        if (count == 2){
            cout << "YES\n";
        } else{
            cout << "NO\n";
        }
    }

    
    return 0;
}
