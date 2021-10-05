#include <bits/stdc++.h>

using namespace std;

long long a[32];
long long b[32];

int main(){
    unordered_map<int, bool> a_map;
    long long n;
    long long m;
    bool result = true;

    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        a_map[a[i]] = true;
    }

    cin >> m;
    for (int i = 0; i < m; i++){
        cin >> b[i];
        if (a_map[b[i]] == 0){
            result = false;
        }
    }
    cout << result;
    
    return 0;
    
 
}
