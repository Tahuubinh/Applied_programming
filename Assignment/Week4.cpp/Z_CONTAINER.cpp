#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;

int H, W, N;
int h[14], w[14], a[31][31];
bool ans;

bool check(int btr, int r, int c){
    for (int i = c; i < c + w[btr]; ++i){
        if (a[r][i]){
            return false;
        }
    }
    for (int i = r + 1; i < r + h[btr] - 1; ++i){
        if (a[i][c] || a[i][c + w[btr] - 1]){
            return false;
        }
    }
    for (int i = c; i < c + w[btr]; ++i){
        if (a[r + h[btr] -1][i]){
            return false;
        }
    }
    return true;
}

//should use color for 0, test codeforce is not good
void color(int btr, int r, int c){
    for (int i = c; i < c + w[btr]; ++i){
        a[r][i] = 1;
    }
    for (int i = r + 1; i < r + h[btr] - 1; ++i){
        a[i][c] = a[i][c + w[btr] - 1] = 1;
    }
    for (int i = c; i < c + w[btr]; ++i){
        a[r + h[btr] -1][i] = 1;
    }
}

void Try(int btr){
    if (btr > N){
        ans = 1;
        return;
    } else{
        for (int i = 1; i <= H; ++i){
            for (int j = 1; j <= W; ++j){
                if (check(btr, i, j)){
                    color(btr, i, j);
                    Try(btr + 1);
                    color(btr, i, j);
                }
            }
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> H >> W;
    cin >> N;
    for (int i = 1; i <= N; ++i){
        cin >> h[i] >> w[i];
    }
    Try(1);
    cout << ans;
    return 0;
}
