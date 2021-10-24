#include<bits/stdc++.h>
#define HNT   ios_base::sync_with_stdio(false);   cin.tie(0);
using namespace std;

int duyet(int X, int p) {
    if(__builtin_popcount(X) == n) return c[p][0];
    if (save[X][p] != -1) return save[X][p];
    int ans = 2e9;
    for (int s = 0; s < n; ++s){
        if ((X >> s & 1) == 0) {
            ans = min(ans, c[p][s]) + duyet(1 << s | X, s));
        }
    }
    save[X][p] = ans;
    return ans;
}

int main() {
    HNT;

    return 0;
}

