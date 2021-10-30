#include <bits/stdc++.h>
using namespace std;
 
int n, m, cnt, temp1, temp2;
bool holes[13][13], b[13], sum[25], sub[25];
 
// bool check(int m, int n){
//     if (holes[m][n]){
//         return false;
//     }
//     if (b[n]){
//         return false;
//     }
//     if (sum[m + n]){
//         return false;
//     }
//     if (sub[m - n + 12]){
//         return false;
//     }
//     return true;
// }
 
void Try(int btr){
        for (int i = 1; i <= n; ++i){
            //if (check(btr, i)){
            if (!holes[btr][i] && !b[i] && !sum[btr + i] && !sub[btr - i + 12]){
                //a[btr] = i;
                int temp1 = btr + i;
                int temp2 = btr - i + 12;
                b[i] = 1;
                sum[temp1] = 1;
                sub[temp2] = 1;
                if (btr == n){
                    ++cnt;
                } else{
                    Try(btr + 1);
                }
                b[i] = 0;
                sum[temp1] = 0;
                sub[temp2] = 0;
            }
        }
    
}
 
int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    while (true){
        cin >> n >> m;
        if (!n && !m){
            break;
        }
        cnt = 0;
        memset(b, 0, sizeof b);
        memset(sum, 0, sizeof sum);
        memset(sub, 0, sizeof sub);
        memset(holes, 0, sizeof holes);
        // for (int i = 1; i <= n; ++i){
        //     for (int j = 1; j <= n; ++j){
        //         holes[i][j] = 0;
        //     }
        // }
        for (int i = 1; i <= m; ++i){
            cin >> temp1 >> temp2;
            holes[temp1][temp2] = 1;
        }
 
        Try(1);
        cout << cnt << '\n';
    }
    
    return 0;
}