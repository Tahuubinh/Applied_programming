#include<bits/stdc++.h>
#define HNT   ios_base::sync_with_stdio(false);   cin.tie(0);
using namespace std;
unsigned long long C[1001][1001];
unsigned long long m = 1e9 + 7;

unsigned long long binom(unsigned long long n, unsigned long long k){
    /*int res = 1;
    for (int i = 1; i <= k; i++){
        res = (res *n/i)%m;
        n--;
    }
    return res;*/
    //# Khử đệ quy
    for (unsigned long long i = 1; i <= n; i++) {
        C[i][0] = 1;
        C[i][i] = 1;
        for( unsigned long long j = 1; j < i; j++) {
            C[i][j] = C[i - 1][j]%m+ C[i - 1][j - 1]%m;
        }
    }
    return C[n][k]%m;
}

int main() {
    HNT;

    unsigned long long n, k;
    cin >> k >> n;
    cout << binom(n,k) % m <<endl;

    return 0;
}
