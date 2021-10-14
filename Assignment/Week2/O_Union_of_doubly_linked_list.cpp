#include <bits/stdc++.h>
using namespace std;

int n, zi;
int l[102], r[102], z[102];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> l[i] >> r[i];
        if (!l[i]){
            z[++zi] = i; //node that not has left
        }
    }
    for (int i = 1; i < zi; ++i){
        int temp = z[i];
        while (r[temp]){
            temp = r[temp];  // to the right of the list
        }
        // connect to next list without left
        r[temp] = z[i + 1];
        l[z[i + 1]] = temp;
    }

    for (int i = 1; i <= n; ++i){
        cout << l[i] << ' ' << r[i] << '\n';
    }

    
    return 0;
}
