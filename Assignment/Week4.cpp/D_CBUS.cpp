#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;

int n, k, passengers, dist;
int res = INT_MAX, mindist = INT_MAX;
int a[25][25], b[25], place[25];

bool check(int i, int temp){
    if (passengers == k && i <= n){
        return false;
    }
    if (i > n && !b[i - n]){
        return false;
    }
    if (a[temp][i] == 0){
        return false;
    }
    if (b[i]){
        return false;
    }
    return true;
}

void Try(int btr){
    if (btr > 2*n){
        int temp = place[btr - 1];
        dist += a[temp][0];
        if (dist < res){
            res = dist;
        }
        dist -= a[temp][0];
    } else{
        for (int i = 1; i <= 2*n; ++i){
            if (check(i, place[btr - 1])){
                int temp = place[btr - 1];
                dist += a[temp][i];
                if (dist + mindist * (2*n - btr) >= res){
                    dist -= a[temp][i];
                    continue;
                }
                place[btr] = i;
                b[i] = 1;
                if (i > n){
                    --passengers;
                } else{
                    ++passengers;
                }
                Try(btr + 1);
                if (i > n){
                    ++passengers;
                } else{
                    --passengers;
                }
                b[i] = 0;
                dist -= a[temp][i];
            }
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n >> k;
    for (int i = 0; i <= 2*n; ++i){
        for (int j = 0; j <= 2*n; ++j){
            cin >> a[i][j];
            if (a[i][j] && a[i][j] < mindist){
                mindist = a[i][j];
            }
        }
    }
    Try(1);
    cout << res;

    return 0;
}
