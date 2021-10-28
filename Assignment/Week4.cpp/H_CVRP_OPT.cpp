#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;

int n, k, q, cnt, stop;
int d[14], visited[14], truck[6], load[6], numplace;
int cost, c[14][14], dest[14], mindist = INT_MAX;

bool checkNext(int btr, int i){
    if (!i){
        return true;
    }
    if (visited[i]){
        return false;
    }
    if (load[btr] + d[i] > q){
        return false;
    }
    return true;
}

void TryNext(int btr, int van){
    if (btr > k){
        if (numplace == stop)
            if (cost < mindist){
                mindist = cost;
            }
    } else{
        for (int i = 0; i <= n; ++i){
            if (checkNext(btr, i)){
                dest[van] = i;
                cost += c[van][i];
                if (i == 0){
                    TryNext(btr + 1, truck[btr + 1]);
                    cost -= c[van][i];
                    continue;
                }
                visited[i] = 1;
                load[btr] += d[i];
                ++numplace;
                TryNext(btr, i);
                visited[i] = 0;
                load[btr] -= d[i];
                --numplace;
                cost -= c[van][i];
            }
        }
    }
}

void TryFirst(int btr){
    if (btr > k){
        TryNext(1, truck[1]); // Continue with the first truck place
    } else{
        for (int i = truck[btr - 1] + 1; i <= n; ++i){
            if (!visited[i]){
                truck[btr] = i;
                visited[i] = 1;
                load[btr] += d[i];
                cost += c[0][i];
                TryFirst(btr + 1);
                visited[i] = 0;
                load[btr] -= d[i];
                cost -= c[0][i];
            }
        }
    }
    
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n >> k >> q;
    for (int i = 1; i <= n; ++i){
        cin >> d[i];
    }
    for (int i = 0; i <= n; ++i){
        for (int j = 0; j <= n; ++j){
            cin >> c[i][j];
        }
    }
    stop = n - k;
    TryFirst(1);
    cout << mindist;
    
    return 0;
}
