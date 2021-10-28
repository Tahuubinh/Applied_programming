#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;

int n, k, q, cnt, stop;
int d[11], visited[11], truck[6], load[6], numplace;

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

void TryNext(int btr){
    if (btr > k){
        if (numplace == stop)
            ++cnt;
    } else{
        for (int i = 0; i <= n; ++i){
            if (checkNext(btr, i)){
                //cout << i;
                if (i == 0){
                    TryNext(btr + 1);
                    continue;
                }
                //cout << btr;
                visited[i] = 1;
                load[btr] += d[i];
                ++numplace;
                TryNext(btr);
                visited[i] = 0;
                load[btr] -= d[i];
                --numplace;
            }
        }
    }
}

void TryFirst(int btr){
    if (btr > k){
        TryNext(1); // Continue with the first truck place
    } else{
        for (int i = truck[btr - 1] + 1; i <= n; ++i){
            if (!visited[i]){
                truck[btr] = i;
                visited[i] = 1;
                load[btr] += d[i];
                TryFirst(btr + 1);
                visited[i] = 0;
                load[btr] -= d[i];
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
    stop = n - k;
    TryFirst(1);
    cout << cnt;
    
    return 0;
}
